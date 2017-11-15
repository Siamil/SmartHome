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

void House::closeWindows()
{

    for (int i = 0; i < kitchen->getNumOfWindows(); i++)
        kitchen->getWindow(i)->setOpen(false);
}

void House::openWindows()
{
    for (int i = 0; i < kitchen->getNumOfWindows(); i++)
        kitchen->getWindow(i)->setOpen(true);
}

void House::turnOnHeat()
{
    for (int i = 0; i < kitchen->getNumOfHeaters(); i++)
        kitchen->getHeat(i)->setIsTurned(true);
}

void House::turnOffHeat()
{
    for (int i = 0; i < kitchen->getNumOfHeaters(); i++)
        kitchen->getHeat(i)->setIsTurned(false);
}

House::House()
{



}

void House::initialize()
{
    kitchen = new Kitchen(2, 1);
    hall = new Hall();
    bedroom = new Bedroom();
    hall->setNumOfWindows(3);
    hall->setNumOfHeaters(2);
    bedroom->setNumOfHeaters(2);
    bedroom->setNumOfWindows(1);

}
