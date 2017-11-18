#include "heatui.h"

void HeatUI::setHeat(Heat *value)
{
    heat = value;
}



void HeatUI::draw(QPainter *painter, QSize size, QPoint point, qreal angle)
{
    int h = size.height();
    h = h * 1/6;
    int w = size.width();
    w = w * 1/8;
    painter->save();
    QPen pen(Qt::black);
    QBrush brush(Qt::Dense2Pattern);
    brush.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);
    QPoint p2(point.x() + w/4, point.y()+ h/4);
    QPoint p3(point.x() + w/4, point.y()+ h/4*2);
    QPoint p4(point.x() + w/4 , point.y()+ h/4*3);
    QPoint p5(point.x() + w/4 , point.y()+ h);
    QRect rec1(point, p2);
    QRect rec2(point, p3);
    QRect rec3(point, p4);
    QRect rec4(point, p5);
    painter->translate(+point.x() ,+ point.y() );
    painter->rotate(360-angle);
    painter->translate(-point.x() ,- point.y() );

    if(heat->getIsTurned())
    {

        brush.setColor(Qt::red);
        painter->setBrush(brush);
        painter-> drawRect(rec1);
        painter-> drawRect(rec2);
        painter-> drawRect(rec3);
        painter-> drawRect(rec4);
    }
    else
    {
        brush.setColor(Qt::black);
        painter->setBrush(brush);
        painter-> drawRect(rec1);
        painter-> drawRect(rec2);
        painter-> drawRect(rec3);
        painter-> drawRect(rec4);

    }
    painter->restore();
}

HeatUI::HeatUI()
{

}
