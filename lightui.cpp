#include "lightui.h"

Light *LightUI::getLight() const
{
    return light;
}

void LightUI::setLight(Light *value)
{
    light = value;
}

LightUI::LightUI()
{

}

void LightUI::draw(QPainter *painter, QSize size, QPoint point, qreal angle)
{
    int h = size.height();
    h = h * 1/15;
    int w = size.width();
    w = w * 1/30;
    QBrush brush(Qt::HorPattern);
    painter->save();
    QPen pen(Qt::black);
    pen.setWidth(4);
    painter->setPen(pen);
    QRect rec(point.x(), point.y(), w, h);
    QRect rec2(point.x()+ (w*1/6), point.y()+h, w*2/3, h*2/3);
    int startAngle = -50 * 16;
    int spanAngle = 280 * 16;
    painter->drawRect(rec2);
    //painter->setBrush(brush);
    painter->fillRect(rec2, brush);


    if(light->getIsTurned())
    {
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(rec);
    }
    else  painter->drawArc(rec, startAngle, spanAngle);

    painter->restore();
}
