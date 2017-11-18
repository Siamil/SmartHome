#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "houseui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    HouseUI *houseUI;
    House *house;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent* e);

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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
