#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client
{
public:
    Client(int _ID, QTcpSocket *_socket);
    int ID;
    bool connected;
    bool ready;
    QTcpSocket* socket;
};

#endif // CLIENT_H
