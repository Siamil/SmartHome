#ifndef KITCHEN_H
#define KITCHEN_H
#include "room.h"


class Kitchen : public Room
{
    QVector <Window*> windows;
    QVector <Heat*> heaters;
    int numOfWindows;
    int numOfHeaters;
    int temperature;
    int lightness;
public:
    Kitchen();
    Window *getWindow(int index);
};

#endif // KITCHEN_H
