#include "door.h"

bool Door::getOpen() const
{
    return open;
}

void Door::setOpen(bool value)
{
    open = value;
}

Door::Door()
{

}
