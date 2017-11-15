#include "kitchen.h"

Kitchen::Kitchen()
{
    for (int i =0; i < this->getNumOfWindows(); i++)
    {
        Window *window = new Window();
        windows.push_back(window);
    }
}

Window *Kitchen::getWindow(int index)
{
    return windows[index];
}
