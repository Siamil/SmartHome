#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>

class Server : public QTcpServer
{
    QTcpServer* server;
    QTcpSocket* client;
public:

    Server();
    public slots:
    void startServer();
    void newConnectionToServer();
    void newMessageToServer();
};

#endif // SERVER_H
