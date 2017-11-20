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
    QVector<QJsonObject> jVector;
    QJsonObject jKitchen;
    QJsonObject jHall;
    QJsonObject jBedroom;
    QJsonObject jHouse;
    jVector.push_back(jKitchen);
    jVector.push_back(jHall);
    jVector.push_back(jBedroom);
    jVector.push_back(jHouse);
    for (int i = 0; i < numOfRooms; i++)
    {
        Room *room = rooms[i];
        jVector[i].insert(QString("Heat"), QJsonValue(rooms[i]->getHeat(0)->getIsTurned()));
        jVector[i].insert(QString("Light"), QJsonValue(rooms[i]->getLight()->getIsTurned()));
        jVector[i].insert(QString("Door"), QJsonValue(rooms[i]->getDoor(0)->getOpen()));
        jVector[i].insert(QString("Window"), QJsonValue(rooms[i]->getWindow(0)->getOpen()));

    }
      jHouse.insert(QString("Kitchen"), QJsonValue(jVector[0]));
      jHouse.insert(QString("Hall"), QJsonValue(jVector[1]));
      jHouse.insert(QString("Bedroom"), QJsonValue(jVector[2]));
      document->setObject(jHouse);
      return document;
}

void House::fromJson(QJsonDocument *document)
{

    QVector<QJsonObject> jVector;
    QJsonObject jHouse = document->object();
    QJsonObject jKitchen;
    jKitchen.insert(QString("Kitchen"), jHouse.value(QString("Kitchen")));
    QJsonObject jHall;
    jHall.insert(QString("Hall"), jHouse.value(QString("Hall")));
    QJsonObject jBedroom;
    jBedroom.insert(QString("Bedroom"), jHouse.value(QString("Bedroom")));
    jVector.push_back(jKitchen);
    jVector.push_back(jHall);
    jVector.push_back(jBedroom);
    for (int i = 0; i < numOfRooms; i++)
    {
        boolean test = jVector[i].value(QString("Window")).toBool();
        Room *room = rooms[i];
       if((jVector[i].value(QString("Window"))).toBool()){
           openWindows(room);
       }
       else closeWindows(room);
       if((jVector[i].value(QString("Door"))).toBool())
       {
           openDoors(room);
       }
       else closeDoors(room);
       if((jVector[i].value(QString("Heat"))).toBool())
       {
           turnOnHeat(room);
       }
       else turnOffHeat(room);

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
