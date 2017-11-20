#include "mainwindow.h"
#include "ui_mainwindow.h"

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


    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllWindows();
    else house->closeWindows(activeRoom);
}




void MainWindow::on_bKopenwindows_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllWindows();
    else house->openWindows(activeRoom);

    house->fromJson(house->toJson());
}

void MainWindow::on_bHeatTurnOn_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOnAllHeat();
    else house->turnOnHeat(activeRoom);
}

void MainWindow::on_bHeatTurnOff_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOffAllHeat();
    else house->turnOffHeat(activeRoom);
}

void MainWindow::on_bOpenDoors_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllDoors();
    else house->openDoors(activeRoom);

}

void MainWindow::on_bCloseDoors_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllDoors();
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
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOnAllLight();
    else house->turnOnLight(activeRoom);
}

void MainWindow::on_bTurnOffLight_clicked()
{
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOffAllLight();
    else house->turnOffLight(activeRoom);
}
