#ifndef HOUSE_H
#define HOUSE_H
#include <QtCore>
#include <QVector>
#include "room.h"



class House
{
    int temperature;
    int lightness;
    QVector <*Room> rooms;
    int numOfRooms;

public:
    House();


    int getNumOfRooms() const;
    void setNumOfRooms(int value);
};

#endif // HOUSE_H
