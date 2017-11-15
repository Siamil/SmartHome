#include "house.h"



int House::getNumOfRooms() const
{
    return numOfRooms;
}

void House::setNumOfRooms(int value)
{
    numOfRooms = value;
}

Bedroom *House::getBedroom() const
{
    return bedroom;
}

void House::setBedroom(Bedroom *value)
{
    bedroom = value;
}

Hall *House::getHall() const
{
    return hall;
}

void House::setHall(Hall *value)
{
    hall = value;
}

Kitchen *House::getKitchen() const
{
    return kitchen;
}

void House::setKitchen(Kitchen *value)
{
    kitchen = value;
}

int House::getLightness() const
{
    return lightness;
}

void House::setLightness(int value)
{
    lightness = value;
}

int House::getTemperature() const
{
    return temperature;
}

void House::setTemperature(int value)
{
    temperature = value;
}

House::House()
{

    kitchen = new Kitchen();
    hall = new Hall();
    bedroom = new Bedroom();
    kitchen->setNumOfWindows(2);
    kitchen->setNumOfHeaters(1);
    hall->setNumOfWindows(3);
    hall->setNumOfHeaters(2);
    bedroom->setNumOfHeaters(2);
    bedroom->setNumOfWindows(1);

}
