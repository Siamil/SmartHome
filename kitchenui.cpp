#include "kitchenui.h"



void KitchenUI::Initialize(Room *value)
{
    kitchenPtr = value;
    for (int i =0; i < kitchenPtr -> getNumOfWindows(); i++)
    {
        WindowUI *windowUI = new WindowUI();
        windowUI->setWindow(kitchenPtr->getWindow(i));
        windowsUI.push_back(windowUI);
    }
    for (int j =0; j < kitchenPtr -> getNumOfHeaters(); j++)
    {
        HeatUI *heatUI = new HeatUI();
        heatUI->setHeat(kitchenPtr->getHeat(j));
        heatersUI.push_back(heatUI);
    }


    for (int j =0; j < kitchenPtr -> getNumOfDoors(); j++)
    {
        DoorUI *doorUI = new DoorUI();
        doorUI->setDoor(kitchenPtr->getDoor(j));
        doorsUI.push_back(doorUI);
    }
    lightUI = new LightUI();
    lightUI ->setLight(kitchenPtr->getLight());
}

KitchenUI::KitchenUI(QWidget *parent) : QWidget(parent)
{




}



void KitchenUI::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);

    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    this->setAutoFillBackground(true);
    this->setStyleSheet(" border: 3px solid black;");

    drawFrame(&painter);
    fillFrame(&painter);
    drawWindows(&painter);
    drawHeats(&painter);
    drawDoors(&painter);
    drawLight(&painter);



}

void KitchenUI::drawFrame(QPainter *painter)
{
    painter->save();
    QPen pen(Qt::black);
    pen.setWidth(5);
    painter->setPen(pen);
    h = this->size().height();
    w = this->size().width();
    setPoints();
    QPainterPath path;
    QBrush brush(Qt::red);
    path.moveTo(points[1]);
    path.lineTo(points[2]);
    path.moveTo(points[3]);
    path.lineTo(points[4]);
    path.lineTo(points[5]);
    path.lineTo(points[6]);
    path.moveTo(points[7]);
    path.lineTo(points[8]);
    path.lineTo(points[9]);
    path.moveTo(points[10]);
    path.lineTo(points[11]);
    path.lineTo(points[12]);
    path.lineTo(points[1]);
    painter->drawPath(path);
    painter->restore();


}

void KitchenUI::drawWindows(QPainter *painter)
{


    windowsUI[0]->draw(painter, this->size(), points[2], points[3], 180);
    windowsUI[1]->draw(painter, this->size(), points[7], points[6], 0);

}

void KitchenUI::setPoints()
{
    points.clear();
    QPoint blankpoint(0, 0);
    QPoint p1(w*1/10, h*4/10);
    QPoint p2(w*1/10, h*3/10);
    QPoint p3(w*1/10, h*2/10);
    QPoint p4(w*1/10, h*1/10);
    QPoint p5(w*7/10, h*1/10);
    QPoint p6(w*7/10, h*2/10);
    QPoint p7(w*7/10, h*3/10);
    QPoint p8(w*7/10, h*9/10);
    QPoint p9(w*19/30, h*9/10);
    QPoint p10(w*15/30, h*9/10);
    QPoint p11(w*3/10, h*9/10);
    QPoint p12 (w*3/10, h*4/10);
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

void KitchenUI::drawHeats(QPainter *painter)
{
    heatersUI[0] -> draw(painter, this->size(), points[12], 0);
}

void KitchenUI::drawDoors(QPainter *painter)
{
    doorsUI[0] -> draw(painter, this->size(), points[9], points[10]);

}

void KitchenUI::drawLight(QPainter *painter)
{
    QPoint point(w/2, h/2);
    lightUI -> draw(painter, this->size(), point);
}

void KitchenUI::fillFrame(QPainter *painter)
{
    QPainterPath path;

    QBrush brush(Qt::DiagCrossPattern);
    QImage img(":/new/prefix1/kitchentexture.jpg");
    brush.setTextureImage(img);
    brush.setStyle(Qt::TexturePattern);

    path.moveTo(points[1]);
    for( int i = 2; i < points.size(); i++) path.lineTo(points[i]);
    painter->fillPath(path, brush);


}
