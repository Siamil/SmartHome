#include "doorui.h"

void DoorUI::setDoor(Door *value)
{
    door = value;
}

DoorUI::DoorUI()
{

}

void DoorUI::draw(QPainter *painter, QSize size, QPoint point, QPoint point2, qreal angle)
{
    int h = size.height();
    h = h * 1/10;
    int w = size.width();
    w = w * 2/30;
    painter->save();
    QColor color(170, 0, 0);
    QPen pen(color);
    pen.setWidth(8);

    painter->setPen(pen);

    if(door->getOpen())
    {
        painter->translate(+point.x() ,+ point2.y());
        painter->rotate(angle);
        painter->translate(-point.x() ,- point2.y());
        QPoint point_2((point.x() + (w)), point2.y() - (h)) ;
        painter-> drawLine(point, point_2);

    }
    else painter -> drawLine(point, point2);
    painter->restore();

}
