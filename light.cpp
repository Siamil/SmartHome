#include "light.h"

bool Light::getIsTurned() const
{
    return isTurned;
}

void Light::setIsTurned(bool value)
{
    isTurned = value;
}

Light::Light()
{

}
