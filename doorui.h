#ifndef DOORUI_H
#define DOORUI_H
#include "door.h"
#include <QPainter>

class DoorUI
{
    Door *door;

public:
    DoorUI();
    void draw(QPainter *painter, QSize size, QPoint point, QPoint point2, qreal angle = 0);
    void setDoor(Door *value);
};

#endif // DOORUI_H
