#ifndef HOUSEUI_H
#define HOUSEUI_H
#include "house.h"
#include "kitchenui.h"
#include "hallui.h"
#include "bedroomui.h"



class HouseUI : public House
{
    House *house;
    KitchenUI * kitchenUI;
    HallUI * hallUI;
    BedroomUI * bedroomUI;
public:

    HouseUI(House *house);
    House *getHouse() const;
    void setHouse(House *value);
};

#endif // HOUSEUI_H
