#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "lightstagewindow.h"
#include <QByteArray>

using namespace std;

class Client : public QObject
{
    Q_OBJECT
    enum State {IDLE, CALIBRATING, SCANNING};
public:
    explicit Client(QObject *parent = nullptr, int screenShift = 0, std::string clientID = 0);

private:
    LightstageWindow lightstageWindows[3];
    QString imagePath;
    QTcpSocket socket;
    State state;
    std::string id;
    QPixmap scanBuffer[3]; //not optimal. uses nearly twice as much storage as needed. but it works. Could be solved using a list
    QPixmap standby;
    int delay;
    void sendToServer(QString message);
    void connectToServer(const QString &hostName, const qint16 &port);
    int calibrate();
    int scan();
    void showPixmaps(QPixmap pixmap[]);
    void showPixmap(QPixmap& pixmap);
    void loadImagesIntoBuffer(QString file);

public slots:

private slots:
    void onConnected();
    void onReadyRead();
};

#endif // CLIENT_H
