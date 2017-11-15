#ifndef HOUSE_H
#define HOUSE_H
#include <QtCore>
#include <QVector>
#include "kitchen.h"
#include "hall.h"
#include "bedroom.h"



class House
{
    int temperature;
    int lightness;
    Kitchen *kitchen;
    Hall *hall;
    Bedroom *bedroom;
    int numOfRooms;

public:
    House();


    int getNumOfRooms() const;
    void setNumOfRooms(int value);
    Bedroom *getBedroom() const;
    void setBedroom(Bedroom *value);
    Hall *getHall() const;
    void setHall(Hall *value);
    Kitchen *getKitchen() const;
    void setKitchen(Kitchen *value);
    int getLightness() const;
    void setLightness(int value);
    int getTemperature() const;
    void setTemperature(int value);
};

#endif // HOUSE_H
