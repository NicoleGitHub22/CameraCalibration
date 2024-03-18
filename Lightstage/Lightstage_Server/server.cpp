//=============================================================================
// The server is the heart of the server program. It manages the communication
// with the clients and their connection states.
//=============================================================================

#include "server.h"
#include <string>
#include "scanner.h"

Server::Server(QObject *parent) : QObject(parent)
{
    int port = 50100; //arbitrarily chosen

    connect(&server, &QTcpServer::newConnection, this, &Server::onNewConnection);

    if(server.listen(QHostAddress::Any, port)){
        qInfo() << "Listening . . .";
    }else{
        qWarning() << "Could not start server on port " << port;
    }

    //capture.printInfo();
    begin_time = clock();
}

void Server::onNewConnection(){
    const auto cSocket = server.nextPendingConnection();

    if(cSocket == nullptr)
        return;

    qInfo() << "Client connected!";

    Client* client = new Client(-1, cSocket);
    clients.insert(this->getClientKey(cSocket), client);

    connect(cSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(cSocket, &QTcpSocket::disconnected, this, &Server::onDisconnect);
}

void Server::onReadyRead(){
    const auto cSocket = qobject_cast<QTcpSocket*>(sender());

    if(cSocket == nullptr)
        return;

    const auto message = cSocket->readAll().toStdString();

    std::string delimiter = ":";
    std::string prefix =  message.substr(0, message.find(delimiter));

    if (prefix == "/c") {
        std::string ID = message.substr(message.find(delimiter) + 1, message.length());

        clients.value(this->getClientKey(cSocket))->ID = std::stoi(ID);
        emit newConnection(std::stoi(ID));
    }
    else if(prefix == "/s"){
        std::string infoText = message.substr(message.find(delimiter) + 1, message.length());

        if(infoText == "scanned"){
            scan();
        }
        else if(infoText == "calibrated")   emit calibrated();
    }
    else{
        qDebug() << "Message from a client uses an unknown prefix. Please contact your nearest IT expert to fix this issue.";
        qDebug() << QString::fromStdString(message);
    }
}

void Server::onDisconnect(){
    const auto client = qobject_cast<QTcpSocket*>(sender());

    if(client == nullptr)
        return;

    qInfo() << "Client disconnected!";
    emit disconnect(clients.value(this->getClientKey(client))->ID);
    clients.remove(this->getClientKey(client));
}

void Server::onCalibrate()
{
    int error = scanner.setUpCal();
    if(error == ERROR_OK){
        emit simpleStateUpdate("Taking images...", false);
    }
    sendToAllClients(QString("calibrate"));
}

void Server::onScan(int maxLevelOfDetail)
{
    int error = scanner.setUp(maxLevelOfDetail);
    if(error == ERROR_OK){
        emit simpleStateUpdate("Scanning...", false);
        showCurrentSH(0,0);
    }
}

void Server::calibrate(){
    bool finishedAllPhotos = scanner.scanNextCal();
    if(finishedAllPhotos){
        scanner.cleanUp();
        emit calibrated();
    }
    else{
        showCurrentCalibrationImage(scanner.GetCurrentI());
    }
}

void Server::scan(){
    bool finishedAllScans = scanner.scanNextSH();

    emit scanProgress(scanner.getProgess());

    if(finishedAllScans){
        scanner.cleanUp();
        //sendToAllClients(QString("scanned"));
        qDebug() << "sanned";
        emit scanned();
    }
    else
        showCurrentSH(scanner.getCurrentL(), scanner.getCurrentM());
}

void Server::showCurrentSH(int l, int m)
{
    QString scan_file = "scan:SPH-" + QString::number(l) + "-" + QString::number(m);
    sendToAllClients(scan_file);
}

void Server::showCurrentCalibrationImage(int i)
{
    QString cal_file = "cal:cal-" + QString::number(i);
    sendToAllClients(cal_file);
}

void Server::onClientDelayChanged(int delay, int clientID)
{
    sendToClient(clientID, QString("delay:").append(QString::number(delay)));
}

QString Server::getClientKey(QTcpSocket *client){
    return client->peerAddress().toString().append(":").append(QString::number(client->peerPort()));
}

void Server::sendToClient(int clientID, QString message)
{
    QByteArray ba = message.toUtf8();
    for(auto &client : qAsConst(clients)){
        if(client->ID == clientID){
            client->socket->write(ba);
            client->socket->flush();
            break;
        }
    }
}

void Server::sendToAllClients(QString message)
{
    QByteArray ba = message.toUtf8();
    for(auto &client : qAsConst(clients)){
        client->socket->write(ba);
        client->socket->flush();
    }
}

