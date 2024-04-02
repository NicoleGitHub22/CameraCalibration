#include "client.h"

Client::Client(int _ID, QTcpSocket* _socket)
{
    ID = _ID;
    socket = _socket;
    ready = true;
}
