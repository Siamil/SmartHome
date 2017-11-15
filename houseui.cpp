#include "houseui.h"

House *HouseUI::getHouse() const
{
    return house;
}

void HouseUI::setHouse(House *value)
{
    house = value;
}

HouseUI::HouseUI(House *house)
{

    int num = house->getKitchen()->getNumOfWindows();
}
