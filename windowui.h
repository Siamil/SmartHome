#ifndef WINDOWUI_H
#define WINDOWUI_H
#include "window.h"
#include <QPainter>
#include <math.h>
#include <QDebug>
#include <QtCore>


class WindowUI
{
    Window *window;
    qreal angle;
public:
    WindowUI();
    Window *getWindow() const;
    void setWindow(Window *value);
    void draw(QPainter *painter, QSize size, QPoint point, QPoint point2);
    qreal getAngle() const;
    void setAngle(const qreal value);
};

#endif // WINDOWUI_H
