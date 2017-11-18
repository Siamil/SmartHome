#include "server.h"

void Server::startServer()
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2000);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionToServer()));
}

void Server::newConnectionToServer()
{
    QTcpSocket* newConnection = server->nextPendingConnection();
}

void Server::newMessageToServer()
{
    QTcpSocket* sender = (QTcpSocket*) QObject::sender();
    // QByteArray array = sender->readAll();
    //QString tmp = QString(array);

}

Server::Server()
{

}
