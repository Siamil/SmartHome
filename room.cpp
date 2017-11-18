#include "room.h"
Light *Room::getLight() const
{
    return light;
}

void Room::setLight(Light *value)
{
    light = value;
}

Room::Room()
{

}

Window *Room::getWindow(int index)
{
    return windows[index];
}

Heat *Room::getHeat(int index)
{
    return heaters[index];
}

Door *Room::getDoor(int index)
{
    return doors[index];

}
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

int Room::getNumOfDoors() const
{
    return numOfDoors;
}

void Room::setNumOfDoors(int value)
{
    numOfDoors = value;
}
