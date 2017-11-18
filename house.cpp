#include "house.h"



int House::getNumOfRooms() const
{
    return numOfRooms;
}

void House::setNumOfRooms(int value)
{
    numOfRooms = value;
}

Room *House::getBedroom() const
{
    return bedroom;
}

void House::setBedroom(Room *value)
{
    bedroom = value;
}

Room *House::getHall() const
{
    return hall;
}

void House::setHall(Room *value)
{
    hall = value;
}

Room *House::getKitchen() const
{
    return kitchen;
}

void House::setKitchen(Room *value)
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

void House::closeWindows(Room *room)
{

    for (int i = 0; i < room->getNumOfWindows(); i++)
        room->getWindow(i)->setOpen(false);
}

void House::openWindows(Room *room)
{
    for (int i = 0; i < room->getNumOfWindows(); i++)
        room->getWindow(i)->setOpen(true);
}

void House::turnOnHeat(Room* room)
{
    for (int i = 0; i < room->getNumOfHeaters(); i++)
        room->getHeat(i)->setIsTurned(true);
}

void House::turnOffHeat(Room *room)
{
    for (int i = 0; i < room->getNumOfHeaters(); i++)
        room->getHeat(i)->setIsTurned(false);
}

void House::closeDoors(Room *room)
{
    for (int i = 0; i < room->getNumOfDoors(); i++)
        room->getDoor(i)->setOpen(false);
}

void House::openDoors(Room* room)
{
    for (int i = 0; i < room->getNumOfDoors(); i++)
        room->getDoor(i)->setOpen(true);
}

void House::closeAllWindows()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfWindows(); i++)
            room->getWindow(i)->setOpen(false);
    }
}

void House::openAllWindows()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfWindows(); i++)
            room->getWindow(i)->setOpen(true);
    }
}

void House::turnOnAllHeat()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfHeaters(); i++)
            room->getHeat(i)->setIsTurned(true);
    }
}

void House::turnOffAllHeat()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfHeaters(); i++)
            room->getHeat(i)->setIsTurned(false);
    }
}

void House::closeAllDoors()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfDoors(); i++)
            room->getDoor(i)->setOpen(false);
    }
}

void House::openAllDoors()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];

        for (int i = 0; i < room->getNumOfDoors(); i++)
            room->getDoor(i)->setOpen(true);
    }
}

House::House()
{



}

void House::initialize()
{
    setNumOfRooms(3);
    kitchen = new Kitchen(2, 1, 1);
    hall = new Hall(2, 2, 2);
    bedroom = new Bedroom(1, 2, 1);
    rooms.push_back(kitchen);
    rooms.push_back(hall);
    rooms.push_back(bedroom);



}
