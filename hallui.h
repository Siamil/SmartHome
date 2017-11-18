#ifndef HALLUI_H
#define HALLUI_H

#include <QWidget>
#include <room.h>
#include "hall.h"
#include "heatui.h"
#include "doorui.h"
#include "windowui.h"
#include "kitchenui.h"


class HallUI : public QWidget
{
    Q_OBJECT
    Room* hallPtr;
    QVector<WindowUI*> windowsUI;
    QVector<HeatUI*> heatersUI;
    QVector<DoorUI*>doorsUI;
    QVector<QPoint> points;
    int h,w;
public:
    HallUI(QWidget *parent = 0);

    void paintEvent(QPaintEvent* e);
    void drawFrame(QPainter *painter);
    void drawWindows(QPainter *painter);
    void setGraphs(QPainter *painter);
    void setPoints();
    void drawHeats(QPainter *painter);
    void drawDoors(QPainter *painter);
    void Initialize(Room *value);
    void fillFrame(QPainter *painter);

signals:

public slots:
};

#endif // HALLUI_H
