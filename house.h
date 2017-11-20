#ifndef HOUSE_H
#define HOUSE_H
#include <QtCore>
#include <QVector>
#include "kitchen.h"
#include "hall.h"
#include "bedroom.h"
#include <QJsonDocument>



class House
{
    int temperature;
    int lightness;
    Room *kitchen;
    Room *hall;
    Room *bedroom;
    QVector<Room*> rooms;
    int numOfRooms;

public:
    House();
    void initialize();


    int getNumOfRooms() const;
    void setNumOfRooms(int value);
    Room *getBedroom() const;
    void setBedroom(Room *value);
    Room *getHall() const;
    void setHall(Room *value);
    Room *getKitchen() const;
    void setKitchen(Room *value);
    int getLightness() const;
    void setLightness(int value);
    int getTemperature() const;
    void setTemperature(int value);
    void closeWindows(Room* room);
    void openWindows(Room* room);
    void turnOnHeat(Room* room);
    void turnOffHeat(Room* room);
    void closeDoors(Room* room);
    void openDoors(Room* room);
    void turnOffLight(Room* room);
    void turnOnLight(Room* room);
    void closeAllWindows();
    void openAllWindows();
    void turnOnAllHeat();
    void turnOffAllHeat();
    void closeAllDoors();
    void openAllDoors();
    void turnOnAllLight();
    void turnOffAllLight();
    QJsonDocument *toJson();
    void fromJson(QJsonDocument *document);



};

#endif // HOUSE_H
