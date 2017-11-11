#include "room.h"

int Room::getNumOfWindows() const
{
    return numOfWindows;
}

void Room::setNumOfWindows(int value)
{
    numOfWindows = value;
}

int Room::getNumOfHeaters() const
{
    return numOfHeaters;
}

void Room::setNumOfHeaters(int value)
{
    numOfHeaters = value;
}

Room::Room()
{

}
