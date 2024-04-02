#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "mainwindow.h"
#include "client.h"
#include "scanner.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

private:
    const int ERROR_OK = 0;
    QTcpServer server;
    QHash<QString, Client*> clients;
    QString getClientKey(QTcpSocket* client);
    Scanner scanner;
    void showCurrentSH(int l, int m);
    void showCurrentCalibrationImage(int i, int j);
    void scan();
    void calibrate();
    void sendToClient(int clientID, QString message);
    void sendToAllClients(QString message);

     clock_t begin_time;

signals:
    void newConnection(int clientID);
    void disconnect(int clientID);
    void calibrated();
    void scanned();
    void scanProgress(int progress);
    void progress(int progress);
    void scanFailed(QString errorMsg);
    void calFailed(QString errorMsgCal);
    void simpleStateUpdate(QString state, bool error);

public slots:
    void onCalibrate();
    void onScan(int maxLevelOfDetail);

    /**
     * @brief sends the updated delay to the specified client.
     * @param delay in milliseconds
     * @param clientID, either 0 or 1
     */
    void onClientDelayChanged(int delay, int clientID);

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisconnect();
};
#endif // SERVER_H
