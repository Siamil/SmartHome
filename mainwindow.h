#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "houseui.h"
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    HouseUI *houseUI;
    House *house;
    Room* activeRoom;
    bool isServer;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent* e);

    bool getIsServer() const;
    void setIsServer(bool value);
    QTcpServer* server;
    QVector<QTcpSocket*> clientSockets;


    // Client part
    QTcpSocket* senderSocket;

public slots:
    void startServer();
    void newConnectionToServer();
    void newMessageToServer();
    void connectToServer();
    void sendMessage(QJsonDocument* document);
    void readMessage();

private slots:


    void on_bKitchen_clicked();

    void on_bBedroom_clicked();

    void on_bKclosewindows_clicked();



    void on_bKopenwindows_clicked();




    void on_bHeatTurnOn_clicked();

    void on_bHeatTurnOff_clicked();

    void on_bOpenDoors_clicked();

    void on_bCloseDoors_clicked();

    void on_bHall_clicked();

    void on_bHouse_clicked();

    void on_bTurnLight_clicked();

    void on_bTurnOffLight_clicked();

    void on_bServer_clicked();

    void on_bClient_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
