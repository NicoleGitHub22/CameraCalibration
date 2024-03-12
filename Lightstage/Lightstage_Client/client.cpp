//=============================================================================
// Handles server communication.
//=============================================================================

#include "client.h"
#include "lightstagewindow.h"
#include <QDebug>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>
#include <QTimer>

#include <unistd.h>

Client::Client(QObject *parent, int screenShift, std::string clientID) : QObject(parent)
{
    id = clientID;
    delay = 0;
    state = IDLE;

    connect(&socket, &QTcpSocket::connected, this, &Client::onConnected);
    connect(&socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);

    connectToServer("localhost", 50100);

    imagePath = "/home/bretznic/Documents/Lightstage/SphericalHarmonics/";

    /* IMPORTANT: make sure the monitors are oriented like this in the nvidia x server settings:
     *
     *      Screen 1:   DP-0    -   DP-2    -   DP-4
     *                           (inverted)
     *
     *      Screen 0:   HDMI0   -   DP-2    -   DP-4    -   DP-0
     */

    for(int i=0; i<3; i++){
        lightstageWindows[i].move(1920 * i + screenShift, 0);
    }
    //For testing:
    scanBuffer[0].load(imagePath + "GraceCathedralIlluminationPattern-" + QString::number(1 + 3*std::stoi(id)) + ".png");
    scanBuffer[1].load(imagePath + "GraceCathedralIlluminationPattern-" + QString::number(2 + 3*std::stoi(id)) + ".png");
    scanBuffer[2].load(imagePath + "GraceCathedralIlluminationPattern-" + QString::number(3 + 3*std::stoi(id)) + ".png");
    showPixmaps(scanBuffer);

    standby.load(imagePath + "standby.jpg");
}

void Client::sendToServer(QString message)
{
    QByteArray ba = message.toUtf8();
    socket.write(ba);
    socket.flush();
}

void Client::connectToServer(const QString &hostName, const qint16 &port)
{
    socket.connectToHost(hostName, port);
    const QByteArray message = QString ("/c:%1").arg(QString::fromStdString(id)).toUtf8();
    socket.write(message);
    socket.flush();
}

///TODO: implement
void Client::calibrate()
{
    state = CALIBRATING;
    state = IDLE;
}

int Client::scan()
{
    showPixmaps(scanBuffer);
    usleep(delay*3000);
    sendToServer("/s:scanned");
    qDebug() << "/s:scanned";
    return 0;
}

void Client::showPixmaps(QPixmap pixmap[])
{
    for(int n=0; n < 3; n++){
        lightstageWindows[n].showPixmap(pixmap[n]);
    }
}

void Client::showPixmap(QPixmap &pixmap)
{
    for(int n=0; n < 3; n++){
        lightstageWindows[n].showPixmap(pixmap);
    }
}

void Client::loadImagesIntoBuffer(QString file)
{
    qDebug() << file;
    scanBuffer[0].load(imagePath + file + "-" + QString::number(1 + 3*std::stoi(id)) + ".bmp");
    scanBuffer[1].load(imagePath + file + "-" + QString::number(2 + 3*std::stoi(id)) + ".bmp");
    scanBuffer[2].load(imagePath + file + "-" + QString::number(3 + 3*std::stoi(id)) + ".bmp");
}

void Client::onConnected()
{
    qDebug() << "Connected to server";
}

void Client::onReadyRead()
{
    const auto message = socket.readAll().toStdString();

    std::string delimiter = ":";
    std::string prefix =  message.substr(0, message.find(delimiter));

    qDebug() << "Message from server: " << QString::fromUtf8(message.c_str());

    if(prefix == "scan"){
        state = SCANNING;
        std::string file = message.substr(message.find(delimiter) + 1, message.length());
        loadImagesIntoBuffer(QString::fromUtf8(file.c_str()));
        scan();
    }
    else if(prefix == "scanned"){
        state = IDLE;
        showPixmap(standby);
    }
    else if(prefix == "calibrate"){
        calibrate();
        QByteArray message = QByteArrayLiteral("/s:calibrated");
        sendToServer("/s:calibrated");
    }
    else if(prefix == "delay"){
        delay = std::stoi(message.substr(message.find(delimiter) + 1, message.length()));
    }
    else{
        qDebug() << "Unknown server command";
    }
}
