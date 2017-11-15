#include "hallui.h"

Room *HallUI::getRoom() const
{
    return room;
}

void HallUI::setRoom(Room *value)
{
    room = value;
}

HallUI::HallUI(QWidget *parent) : QWidget(parent)
{

}

HallUI::HallUI(Room *room)
{
    this->room=room;
}
