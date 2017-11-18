#include "kitchen.h"
#include "room.h"



Kitchen::Kitchen(int numOfWindows, int numOfHeaters, int numOfDoors) :Room()
{
    this->numOfWindows = numOfWindows;
    this->numOfHeaters = numOfHeaters;
    this->numOfDoors = numOfDoors;
    for (int i =0; i < this->getNumOfWindows(); i++)
    {
        Window *window = new Window();
        windows.push_back(window);
    }

    for (int j =0; j < this->getNumOfHeaters(); j++)
    {
        Heat *heat = new Heat();
        heaters.push_back(heat);
    }
    for (int j =0; j < this->getNumOfDoors(); j++)
    {
        Door *door = new Door();
        doors.push_back(door);
    }
    light = new Light();
}


