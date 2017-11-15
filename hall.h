#ifndef HALL_H
#define HALL_H
#include "room.h"


class Hall : public Room
{
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    int numOfWindows;
    int numOfHeaters;
    int temperature;
    int lightness;
public:

    Hall();
};

#endif // HALL_H
