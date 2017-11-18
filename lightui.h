#ifndef LIGHTUI_H
#define LIGHTUI_H
#include "light.h"
#include <QPainter>

class LightUI
{
    Light *light;

public:
    LightUI();

    void draw(QPainter *painter, QSize size, QPoint point, qreal angle = 0);
    Light *getLight() const;
    void setLight(Light *value);
};

#endif // LIGHTUI_H
