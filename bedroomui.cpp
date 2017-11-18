#include "BedroomUI.h"



void BedroomUI::Initialize(Room *value)
{
    bedroomPtr = value;
    for (int i =0; i < bedroomPtr -> getNumOfWindows(); i++)
    {
        WindowUI *windowUI = new WindowUI();
        windowUI->setWindow(bedroomPtr->getWindow(i));
        windowsUI.push_back(windowUI);
    }
    for (int j =0; j < bedroomPtr -> getNumOfHeaters(); j++)
    {
        HeatUI *heatUI = new HeatUI();
        heatUI->setHeat(bedroomPtr->getHeat(j));
        heatersUI.push_back(heatUI);
    }

    for (int j =0; j < bedroomPtr -> getNumOfDoors(); j++)
    {
        DoorUI *doorUI = new DoorUI();
        doorUI->setDoor(bedroomPtr->getDoor(j));
        doorsUI.push_back(doorUI);
    }
}

void BedroomUI::fillFrame(QPainter *painter)
{
    QPainterPath path;

    QBrush brush(Qt::DiagCrossPattern);
    QImage img(":/new/prefix1/bedroomtext.jpg");
    brush.setTextureImage(img);
    brush.setStyle(Qt::TexturePattern);

    path.moveTo(points[1]);
    for( int i = 2; i < points.size(); i++) path.lineTo(points[i]);
    painter->fillPath(path, brush);
}

BedroomUI::BedroomUI(QWidget *parent) : QWidget(parent)
{




}



void BedroomUI::paintEvent(QPaintEvent *e)
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


}

void BedroomUI::drawFrame(QPainter *painter)
{
    painter->save();
    QPen pen(Qt::black);
    pen.setWidth(4);
    painter->setPen(pen);
    h = this->size().height();
    w = this->size().width();
    setPoints();
    QPainterPath path;
    path.moveTo(points[1]);
    path.lineTo(points[2]);
    path.lineTo(points[3]);
    path.lineTo(points[4]);
    path.lineTo(points[5]);
    path.moveTo(points[6]);
    path.lineTo(points[7]);
    path.lineTo(points[8]);
    path.moveTo(points[9]);
    path.lineTo(points[10]);
    path.lineTo(points[11]);
    path.lineTo(points[12]);
    path.lineTo(points[1]);
    painter->drawPath(path);
    painter->restore();


}

void BedroomUI::drawWindows(QPainter *painter)
{


    windowsUI[0]->draw(painter, this->size(), points[5], points[6], 0);
    // windowsUI[1]->draw(painter, this->size(), points[12], points[11], 180);

}

void BedroomUI::setPoints()
{
    points.clear();
    QPoint blankpoint(0, 0);
    QPoint p1(w*2/10, h*9/10);
    QPoint p2(w*3/10, h*9/10);
    QPoint p3(w*5/10, h*9/10);
    QPoint p4(w*7/10, h*9/10);
    QPoint p5(w*7/10, h*5/10);
    QPoint p6(w*7/10, h*4/10);
    QPoint p7(w*7/10, h*3/20);
    QPoint p8(w*3/10, h*3/20);
    QPoint p9(w*2/10, h*3/20);
    QPoint p10(w*2/10, h*3/20);
    QPoint p11(w*2/10, h*4/10);
    QPoint p12 (w*2/10, h*5/10);
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

void BedroomUI::drawHeats(QPainter *painter)
{
    heatersUI[0] -> draw(painter, this->size(), points[2], 90);
    heatersUI[1] -> draw(painter, this->size(), points[3], 90);
}

void BedroomUI::drawDoors(QPainter *painter)
{
    doorsUI[0] -> draw(painter, this->size(), points[8], points[9], 90);

}
