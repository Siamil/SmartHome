#ifndef ROOM_H
#define ROOM_H
#include <window.h>
#include <QVector>
#include "heat.h"


class Room
{
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    int numOfWindows;
    int numOfHeaters;

public:
    Room();
    int getNumOfWindows() const;
    void setNumOfWindows(int value);
    int getNumOfHeaters() const;
    void setNumOfHeaters(int value);
};

#endif // ROOM_H
