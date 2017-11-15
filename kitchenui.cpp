#include "kitchenui.h"



void KitchenUI::Initialize(Kitchen *value)
{
    kitchenPtr = value;
    for (int i =0; i < kitchenPtr -> getNumOfWindows(); i++)
    {
        WindowUI *windowUI = new WindowUI();
        windowUI->setWindow(kitchenPtr->getWindow(i));
        windowsUI.push_back(windowUI);
    }
}

KitchenUI::KitchenUI(QWidget *parent) : QWidget(parent)
{




}



void KitchenUI::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    setPoints();
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    this->setAutoFillBackground(true);
    this->setStyleSheet(" border: 3px solid black;");

    drawFrame(&painter);
    drawWindows(&painter);


}

void KitchenUI::drawFrame(QPainter *painter)
{



    QPainterPath path;

//    QPoint p1(w*1/10, h*4/10);
//    QPoint p2(w*1/10, h*3/10);
//    QPoint p3(w*1/10, h*2/10);
//    QPoint p4(w*1/10, h*1/10);
//    QPoint p5(w*7/10, h*1/10);
//    QPoint p6(w*7/10, h*2/10);
//    QPoint p7(w*7/10, h*3/10);
//    QPoint p8(w*7/10, h*9/10);
//    QPoint p9(w*19/30, h*9/10);
//    QPoint p10(w*17/30, h*9/10);
//    QPoint p11(w*3/10, h*9/10);
//    QPoint p12(w*3/10, h*4/10);

    path.moveTo(*points[1]);
    path.lineTo(*points[2]);
    path.moveTo(*points[3]);
    path.lineTo(*points[4]);
    path.lineTo(*points[5]);
    path.lineTo(*points[6]);
    path.moveTo(*points[7]);
    path.lineTo(*points[8]);
    path.lineTo(*points[9]);
    path.moveTo(*points[10]);
    path.lineTo(*points[11]);
    path.lineTo(*points[12]);
    path.lineTo(*points[1]);
    painter->drawPath(path);



}

void KitchenUI::drawWindows(QPainter *painter)
{

    for (int i = 0; i < kitchenPtr -> getNumOfWindows(); i++)
    {
        windowsUI[i]->draw(painter, size(),*points[2], *points[3]);
    }
}

void KitchenUI::setPoints()
{
    int h = this->size().height();
    int w = size().width();
    QPoint* blankpoint = new QPoint(0, 0);
    QPoint* p1 = new QPoint(w*1/10, h*4/10);
    QPoint* p2 = new QPoint(w*1/10, h*3/10);
    QPoint *p3 = new QPoint(w*1/10, h*2/10);
    QPoint *p4 = new QPoint(w*1/10, h*1/10);
    QPoint *p5 = new QPoint(w*7/10, h*1/10);
    QPoint* p6 = new QPoint(w*7/10, h*2/10);
    QPoint *p7 = new QPoint(w*7/10, h*3/10);
    QPoint *p8 = new QPoint(w*7/10, h*9/10);
    QPoint *p9 = new QPoint(w*19/30, h*9/10);
    QPoint *p10 = new QPoint(w*17/30, h*9/10);
    QPoint *p11 = new QPoint(w*3/10, h*9/10);
    QPoint *p12 = new QPoint(w*3/10, h*4/10);
    points.push_back(blankpoint);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p8);
    points.push_back(p9);
    points.push_back(p10);
    points.push_back(p11);
    points.push_back(p12);
}
