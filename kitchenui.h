#ifndef KITCHENUI_H
#define KITCHENUI_H
#include "kitchen.h"
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <windowui.h>
#include <QVector>
#include <QStyleOption>

class KitchenUI : public QWidget
{
    Q_OBJECT
    Kitchen* kitchenPtr;
    QVector<WindowUI*> windowsUI;
    QVector<QPoint*> points;
public:
    KitchenUI(QWidget *parent = 0);

    void paintEvent(QPaintEvent* e);
    void drawFrame(QPainter *painter);
    void drawWindows(QPainter *painter);
    void setGraphs(QPainter *painter);
    void setPoints();



    void Initialize(Kitchen *value);

signals:

public slots:
};

#endif // KITCHENUI_H
