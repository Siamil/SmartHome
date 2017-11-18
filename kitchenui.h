#ifndef KITCHENUI_H
#define KITCHENUI_H
#include "kitchen.h"
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <windowui.h>
#include <QVector>
#include <QStyleOption>
#include "room.h"
#include "heatui.h"
#include "doorui.h"
#include "lightui.h"

class KitchenUI : public QWidget
{
    Q_OBJECT
    Room* kitchenPtr;
    QVector<WindowUI*> windowsUI;
    QVector<HeatUI*> heatersUI;
    QVector<DoorUI*>doorsUI;
    QVector<QPoint> points;
    LightUI *lightUI;
    int h,w;
public:
    KitchenUI(QWidget *parent = 0);

    void paintEvent(QPaintEvent* e);
    void drawFrame(QPainter *painter);
    void drawWindows(QPainter *painter);
    void setGraphs(QPainter *painter);
    void setPoints();
    void drawHeats(QPainter *painter);
    void drawDoors(QPainter *painter);
    void drawLight(QPainter *painter);
    void fillFrame(QPainter *painter);



    void Initialize(Room *value);

signals:

public slots:
};

#endif // KITCHENUI_H
