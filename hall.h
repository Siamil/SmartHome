#ifndef HALL_H
#define HALL_H
#include "room.h"



class Hall : public Room
{

public:

    Hall(int numOfWindows, int numOfHeaters, int numOfDoors);
};

#endif // HALL_H
