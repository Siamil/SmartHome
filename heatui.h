#ifndef HEATUI_H
#define HEATUI_H
#include "heat.h"
#include <QPainter>
#include <math.h>
#include <QDebug>

class HeatUI
{
    Heat* heat;


public:
    void draw(QPainter *painter, QSize size, QPoint point, qreal angle);
    HeatUI();
    void setHeat(Heat *value);

};

#endif // HEATUI_H
