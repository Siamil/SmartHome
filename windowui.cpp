#include "windowui.h"

Window *WindowUI::getWindow() const
{
    return window;
}

void WindowUI::setWindow(Window *value)
{
    window = value;
}

void WindowUI::draw(QPainter *painter, QSize size, QPoint point, QPoint point2)
{
    int h = size.height();
    h = h * 1/10;
    int w = size.width();
    w = w * 2/30;
    painter->save();
    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter->setPen(pen);
    if(window->getOpen())
    {
    QPoint point_2((point.x() - (w/2)), point2.y() - (h/2)) ;
    painter-> drawLine(point2, point_2);
    QPoint point_3((point.x() - (w/2)), point.y() + (h/2)) ;
    painter-> drawLine(point, point_3 );
}
    else painter -> drawLine(point, point2);
    painter->restore();
}


qreal WindowUI::getAngle() const
{
    return angle;
}

void WindowUI::setAngle(const qreal value)
{
    angle = value;
}

WindowUI::WindowUI()
{
    
}
