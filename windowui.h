#ifndef WINDOWUI_H
#define WINDOWUI_H
#include "window.h"
#include <QPainter>


class WindowUI
{
    Window *window;
public:
    WindowUI();
    Window *getWindow() const;
    void setWindow(Window *value);
    void draw(QPainter *painter, QSize size, QPoint point, QPoint point2);
};

#endif // WINDOWUI_H
