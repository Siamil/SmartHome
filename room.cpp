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

int Room::getLightness() const
{
    return lightness;
}

void Room::setLightness(int value)
{
    lightness = value;
}

int Room::getTemperature() const
{
    return temperature;
}

void Room::setTemperature(int value)
{
    temperature = value;
}

Room::Room()
{
    
}
