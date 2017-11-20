#ifndef ROOM_H
#define ROOM_H
#include <window.h>
#include <QVector>
#include "heat.h"
#include "door.h"
#include "light.h"
#include <QString>


class Room
{
protected:
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    QVector <Door*> doors;
    Light *light;
    int numOfWindows;
    int numOfHeaters;
    int numOfDoors;
    int temperature;
    int lightness;
    QString name;

public:
    Room();
    Room(int numOfWindows, int numOfHeaters, int numOfDoors);
    Window *getWindow(int index);
    Heat *getHeat(int index);
    Door *getDoor(int index);
    int getNumOfWindows() const;
    void setNumOfWindows(int value);
    int getNumOfHeaters() const;
    void setNumOfHeaters(int value);
    int getNumOfDoors() const;
    void setNumOfDoors(int value);
    Light *getLight() const;
    void setLight(Light *value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // ROOM_H
