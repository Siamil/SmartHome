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
    ui->stackedWidget->setCurrentWidget(ui->kitchenUI);

}

void MainWindow::on_bBedroom_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->bedroomUI);
}

void MainWindow::on_bKclosewindows_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->closeWindows(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->closeWindows(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->closeWindows(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllWindows();
}




void MainWindow::on_bKopenwindows_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->openWindows(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->openWindows(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->openWindows(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllWindows();
}

void MainWindow::on_bHeatTurnOn_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->turnOnHeat(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->turnOnHeat(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->turnOnHeat(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOnAllHeat();
}

void MainWindow::on_bHeatTurnOff_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->turnOffHeat(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->turnOffHeat(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->turnOffHeat(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->turnOffAllHeat();
}

void MainWindow::on_bOpenDoors_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->openDoors(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->openDoors(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->openDoors(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->openAllDoors();

}

void MainWindow::on_bCloseDoors_clicked()
{
    if(ui->kitchenUI == (ui->stackedWidget->currentWidget())) house->closeDoors(house->getKitchen());
    if(ui->hallUI == (ui->stackedWidget->currentWidget())) house->closeDoors(house->getHall());
    if(ui->bedroomUI == (ui->stackedWidget->currentWidget())) house->closeDoors(house->getBedroom());
    if(ui->houseUI == ui->stackedWidget->currentWidget()) house->closeAllDoors();
}

void MainWindow::on_bHall_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->hallUI);
}

void MainWindow::on_bHouse_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->houseUI);
}
