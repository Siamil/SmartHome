#ifndef ROOM_H
#define ROOM_H
#include <window.h>
#include <QVector>
#include "heat.h"


class Room
{
protected:
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    int numOfWindows;
    int numOfHeaters;
    int temperature;
    int lightness;

public:
    Room();
    int getNumOfWindows() const;
    void setNumOfWindows(int value);
    int getNumOfHeaters() const;
    void setNumOfHeaters(int value);
    int getLightness() const;
    void setLightness(int value);
    int getTemperature() const;
    void setTemperature(int value);
};

#endif // ROOM_H
