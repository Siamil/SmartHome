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

Room::Room(int numOfWindows, int numOfHeaters, int numOfDoors)
{
    this->numOfWindows = numOfWindows;
    this->numOfHeaters = numOfHeaters;
    this->numOfDoors = numOfDoors;
    for (int i =0; i < this->getNumOfWindows(); i++)
    {
        Window *window = new Window();
        windows.push_back(window);
    }

    for (int j =0; j < this->getNumOfHeaters(); j++)
    {
        Heat *heat = new Heat();
        heaters.push_back(heat);
    }
    for (int j =0; j < this->getNumOfDoors(); j++)
    {
        Door *door = new Door();
        doors.push_back(door);
    }
    light = new Light();
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
