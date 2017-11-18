#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpServer>

class Client
{
    QTcpSocket* senderSocket;
public:
    Client();
public slots:
    void connectToServer();
    void sendMessage();
};

#endif // CLIENT_H
