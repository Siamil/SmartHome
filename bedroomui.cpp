#include "bedroomui.h"

Room *BedroomUI::getRoom() const
{
    return room;
}

void BedroomUI::setRoom(Room *value)
{
    room = value;
}

BedroomUI::BedroomUI(QWidget *parent) : QWidget(parent)
{

}

void BedroomUI::drawFrame(QPainter *painter)
{

}

void BedroomUI::drawWindows(QPainter *painter)
{

}

BedroomUI::BedroomUI(Room *room)
{
    this->room=room;

}
