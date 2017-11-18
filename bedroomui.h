#ifndef BEDROOMUI_H
#define BEDROOMUI_H

#include <QWidget>
#include <room.h>
#include "hall.h"
#include "heatui.h"
#include "doorui.h"
#include "windowui.h"
#include "kitchenui.h"
#include "bedroom.h"

class BedroomUI : public QWidget
{
    Q_OBJECT
    Room* bedroomPtr;
    QVector<WindowUI*> windowsUI;
    QVector<HeatUI*> heatersUI;
    QVector<DoorUI*>doorsUI;
    QVector<QPoint> points;
    int h,w;
public:
    BedroomUI(QWidget *parent = 0);

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

#endif // BEDROOMUI_H
