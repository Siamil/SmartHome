#ifndef BEDROOM_H
#define BEDROOM_H
#include "room.h"


class Bedroom : public Room
{
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    int numOfWindows;
    int numOfHeaters;
    int temperature;
    int lightness;
public:
    Bedroom();
};

#endif // BEDROOM_H
