#include "kitchen.h"

int Kitchen::getNumOfWindows() const
{
    return numOfWindows;
}

void Kitchen::setNumOfWindows(int value)
{
    numOfWindows = value;
}

int Kitchen::getNumOfHeaters() const
{
    return numOfHeaters;
}

void Kitchen::setNumOfHeaters(int value)
{
    numOfHeaters = value;
}

Kitchen::Kitchen(int numOfWindows, int numOfHeaters)
{
    this->numOfWindows=numOfWindows;
    this->numOfHeaters=numOfHeaters;
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
}

Window *Kitchen::getWindow(int index)
{
    return windows[index];
}

Heat *Kitchen::getHeat(int index)
{
    return heaters[index];
}
