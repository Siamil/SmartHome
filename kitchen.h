#ifndef KITCHEN_H
#define KITCHEN_H
#include "room.h"
#include "door.h"


class Kitchen : public Room
{


public:
    Kitchen(int numOfWindows, int numOfHeaters, int numOfDoors);

};

#endif // KITCHEN_H
