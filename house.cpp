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

void House::turnOffLight(Room *room)
{

    room->getLight()->setIsTurned(false);
}

void House::turnOnLight(Room *room)
{
    room->getLight()->setIsTurned(true);
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

void House::turnOnAllLight()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];
        room -> getLight()-> setIsTurned(true);
    }
}

void House::turnOffAllLight()
{
    for(int j = 0; j < getNumOfRooms(); j++)
    {
        Room *room = rooms[j];
        room -> getLight() -> setIsTurned(false);
    }
}

QJsonDocument* House::toJson()
{
    QJsonDocument *document = new QJsonDocument();
    //QVector<QJsonObject> jVector;
    QJsonObject jKitchen;
    QJsonObject jHall;
    QJsonObject jBedroom;
    QJsonObject jHouse;
    //    jVector.push_back(jKitchen);
    //    jVector.push_back(jHall);
    //    jVector.push_back(jBedroom);
    //    jVector.push_back(jHouse);
    //    for (int i = 0; i < numOfRooms; i++)
    //    {
    //        Room *room = rooms[i];
    jKitchen.insert(QString("Heat"), QJsonValue(kitchen->getHeat(0)->getIsTurned()));
    jKitchen.insert(QString("Light"), QJsonValue(kitchen->getLight()->getIsTurned()));
    jKitchen.insert(QString("Door"), QJsonValue(kitchen->getDoor(0)->getOpen()));
    jKitchen.insert(QString("Window"), QJsonValue(kitchen->getWindow(0)->getOpen()));

    jHall.insert(QString("Heat"), QJsonValue(hall->getHeat(0)->getIsTurned()));
    jHall.insert(QString("Light"), QJsonValue(hall->getLight()->getIsTurned()));
    jHall.insert(QString("Door"), QJsonValue(hall->getDoor(0)->getOpen()));
    jHall.insert(QString("Window"), QJsonValue(hall->getWindow(0)->getOpen()));

    jBedroom.insert(QString("Heat"), QJsonValue(bedroom->getHeat(0)->getIsTurned()));
    jBedroom.insert(QString("Light"), QJsonValue(bedroom->getLight()->getIsTurned()));
    jBedroom.insert(QString("Door"), QJsonValue(bedroom->getDoor(0)->getOpen()));
    jBedroom.insert(QString("Window"), QJsonValue(bedroom->getWindow(0)->getOpen()));


    //    }
    jHouse.insert(QString("Kitchen"), QJsonValue(jKitchen));
    jHouse.insert(QString("Hall"), QJsonValue(jHall));
    jHouse.insert(QString("Bedroom"), QJsonValue(jBedroom));
    document->setObject(jHouse);
    return document;
}

void House::fromJson(QJsonDocument *document)
{

    QVector <QJsonObject> jVector;
    QJsonObject jHouse = document -> object();
    QJsonObject jKitchen = jHouse.value(QString("Kitchen")).toObject();
    QJsonObject jBedroom = jHouse.value(QString("Bedroom")).toObject();
    QJsonObject jHall = jHouse.value(QString("Hall")).toObject();



    if((jKitchen.value( QString ("Window") ) ).toBool()){
        openWindows(kitchen);
    }
    else closeWindows(kitchen);
    if((jKitchen.value( QString( "Door" ) ) ).toBool())
    {
        openDoors(kitchen);
    }
    else closeDoors(kitchen);
    if((jKitchen.value( QString ("Heat") ) ).toBool())
    {
        turnOnHeat(kitchen);
    }
    else turnOffHeat(kitchen);
    if((jKitchen.value( QString( "Light" ) ) ).toBool())
    {
        turnOnLight(kitchen);
    }
    else turnOffLight(kitchen);

    if((jBedroom.value( QString ("Window") ) ).toBool()){
        openWindows(bedroom);
    }
    else closeWindows(bedroom);
    if((jBedroom.value( QString( "Door" ) ) ).toBool())
    {
        openDoors(bedroom);
    }
    else closeDoors(bedroom);
    if((jBedroom.value( QString ("Heat") ) ).toBool())
    {
        turnOnHeat(bedroom);
    }
    else turnOffHeat(bedroom);
    if((jBedroom.value( QString( "Light" ) ) ).toBool())
    {
        turnOnLight(bedroom);
    }
    else turnOffLight(bedroom);



    if((jHall.value( QString ("Window") ) ).toBool()){
        openWindows(hall);
    }
    else closeWindows(hall);
    if((jHall.value( QString( "Door" ) ) ).toBool())
    {
        openDoors(hall);
    }
    else closeDoors(hall);
    if((jHall.value( QString ("Heat") ) ).toBool())
    {
        turnOnHeat(hall);
    }
    else turnOffHeat(hall);
    if((jHall.value( QString( "Light" ) ) ).toBool())
    {
        turnOnLight(hall);
    }
    else turnOffLight(hall);



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
    kitchen->setName("kitchen");
    hall->setName("hall");
    bedroom->setName("bedroom");
    rooms.push_back(kitchen);
    rooms.push_back(hall);
    rooms.push_back(bedroom);



}
