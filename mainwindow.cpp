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
   // houseUI = new HouseUI(house);


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
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_bBedroom_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_bKclosewindows_clicked()
{
    house->closeWindows();
}




void MainWindow::on_bKopenwindows_clicked()
{
    house->openWindows();
}

void MainWindow::on_bHeatTurnOn_clicked()
{
    house->turnOnHeat();
}

void MainWindow::on_bHeatTurnOff_clicked()
{
    house->turnOffHeat();
}
