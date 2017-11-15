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
    Kitchen(int numOfWindows, int numOfHeaters);
    Window *getWindow(int index);
    Heat *getHeat(int index);
    int getNumOfWindows() const;
    void setNumOfWindows(int value);
    int getNumOfHeaters() const;
    void setNumOfHeaters(int value);
};

#endif // KITCHEN_H
