#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::getIsServer() const
{
    return isServer;
}

void MainWindow::setIsServer(bool value)
{
    isServer = value;
}

void MainWindow::startServer()
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2000);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionToServer()));
}

void MainWindow::newConnectionToServer()
{
//    ui->serverList->addItem("NEW CONNECTION TO SERVER");
    QTcpSocket* newConnection = server->nextPendingConnection();

    //if (clientSockets == NULL) clientSockets = new QVector<QTcpSocket*>();

    clientSockets.append(newConnection);

    connect(newConnection, SIGNAL(readyRead()), SLOT(newMessageToServer()));
}

void MainWindow::newMessageToServer()
{
    QTcpSocket* sender = (QTcpSocket*) QObject::sender();
    QJsonDocument document = QJsonDocument::fromJson((sender->readAll()));
    QJsonObject jHouse = document.object();
    QJsonObject jRoom;
    if (jHouse.contains("kitchen"))
    {
        jRoom = (jHouse.value("kitchen")).toObject();
        Room* room = house -> getKitchen();
        if (jRoom.contains("Light")) room->getLight()->setIsTurned(jRoom.value("Light").toBool());
        if (jRoom.contains("Window"))
            if(jRoom.value("Window").toBool()) house->openWindows(room);
            else house->closeWindows(room);
        if (jRoom.contains("Door"))
            if(jRoom.value("Door").toBool()) house->openDoors(room);
            else house->closeDoors(room);
        if (jRoom.contains("Heat"))
            if(jRoom.value("Heat").toBool()) house->turnOnHeat(room);
            else house->turnOffHeat(room);
    }
    if (jHouse.contains("hall"))
    {
        jRoom = jHouse.value("hall").toObject();
        Room* room = house -> getHall();
        if (jRoom.contains("Light")) room->getLight()->setIsTurned(jRoom.value("Light").toBool());
        if (jRoom.contains("Window"))
            if(jRoom.value("Window").toBool()) house->openWindows(room);
            else house->closeWindows(room);
        if (jRoom.contains("Door"))
            if(jRoom.value("Door").toBool()) house->openDoors(room);
            else house->closeDoors(room);
        if (jRoom.contains("Heat"))
            if(jRoom.value("Heat").toBool()) house->turnOnHeat(room);
            else house->turnOffHeat(room);
    }
    if(jHouse.contains("bedroom"))
    {
        jRoom = jHouse.value("bedroom").toObject();
        Room* room = house -> getBedroom();
        if (jRoom.contains("Light")) room->getLight()->setIsTurned(jRoom.value("Light").toBool());
        if (jRoom.contains("Window"))
            if(jRoom.value("Window").toBool()) house->openWindows(room);
            else house->closeWindows(room);
        if (jRoom.contains("Door"))
            if(jRoom.value("Door").toBool()) house->openDoors(room);
            else house->closeDoors(room);
        if (jRoom.contains("Heat"))
            if(jRoom.value("Heat").toBool()) house->turnOnHeat(room);
            else house->turnOffHeat(room);
    }

    QJsonDocument *doc(house->toJson());
    QByteArray data = doc->toJson();
    for (int i = 0; i<clientSockets.size();i++)
    clientSockets[i]->write(data);




}

void MainWindow::connectToServer()
{
    senderSocket = new QTcpSocket(this);
    senderSocket->connectToHost(QHostAddress::LocalHost, 2000);
    connect(senderSocket, SIGNAL(readyRead()), SLOT(readMessage()));
}

void MainWindow::sendMessage(QJsonDocument* document )
{
    QByteArray data = document->toJson();
    senderSocket->write(data);

}

void MainWindow::readMessage()
{
    QTcpSocket* sender = (QTcpSocket*) QObject::sender();
    QJsonDocument document = QJsonDocument::fromJson((sender->readAll()));
    house->fromJson(&document);
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    connect(ui->bKitchen, SIGNAL(clicked(bool)), ui->kitchenUI, SLOT(update()));
    house = new House();
    house->initialize();
    ui->kitchenUI->Initialize(house->getKitchen());
    ui->hallUI->Initialize(house->getHall());
    ui->bedroomUI->Initialize(house->getBedroom());
    ui->hKitchenUI->Initialize(house->getKitchen());
    ui->hHallUI->Initialize(house->getHall());
    ui->hBedroomUI->Initialize(house->getBedroom());
    activeRoom = new Room();
    activeRoom = house->getKitchen();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{

}


void MainWindow::on_bKitchen_clicked()
{
    activeRoom = house->getKitchen();
    ui->stackedWidget->setCurrentWidget(ui->kitchenUI);

}

void MainWindow::on_bBedroom_clicked()
{
    activeRoom = house->getBedroom();
    ui->stackedWidget->setCurrentWidget(ui->bedroomUI);
}

void MainWindow::on_bKclosewindows_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Window"), QJsonValue(false));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }

    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllWindows();
    else house->closeWindows(activeRoom);
}




void MainWindow::on_bKopenwindows_clicked()
{
    if(!isServer){
        QJsonObject house;
        QJsonObject property;
        property.insert(QString("Window"), QJsonValue(true));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;

        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllWindows();
    else house->openWindows(activeRoom);

    house->fromJson(house->toJson());
}

void MainWindow::on_bHeatTurnOn_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Heat"), QJsonValue(true));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOnAllHeat();
    else house->turnOnHeat(activeRoom);
}

void MainWindow::on_bHeatTurnOff_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Heat"), QJsonValue(false));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOffAllHeat();
    else house->turnOffHeat(activeRoom);
}

void MainWindow::on_bOpenDoors_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Door"), QJsonValue(true));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllDoors();
    else house->openDoors(activeRoom);

}

void MainWindow::on_bCloseDoors_clicked()
{
    if(!isServer){

        QJsonObject property;
        property.insert(QString("Door"), QJsonValue(false));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));
        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllDoors();
    else house->closeDoors(activeRoom);
}

void MainWindow::on_bHall_clicked()
{
    activeRoom = house->getHall();
    ui->stackedWidget->setCurrentWidget(ui->hallUI);
}

void MainWindow::on_bHouse_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->houseUI);
}

void MainWindow::on_bTurnLight_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Light"), QJsonValue(true));
        QJsonObject room;
        property.insert(activeRoom->getName(), QJsonValue(property));

        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOnAllLight();
    else house->turnOnLight(activeRoom);
}

void MainWindow::on_bTurnOffLight_clicked()
{
    if(!isServer){
        QJsonObject property;
        property.insert(QString("Light"), QJsonValue(false));
        QJsonObject room;
        room.insert(activeRoom->getName(), QJsonValue(property));


        QJsonDocument document;
        document.setObject(room);
        sendMessage(&document);
    }
    else if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOffAllLight();
    else house->turnOffLight(activeRoom);
}

void MainWindow::on_bServer_clicked()
{
    setIsServer(true);

    startServer();

}

void MainWindow::on_bClient_clicked()
{

    setIsServer(false);
    connectToServer();
}
