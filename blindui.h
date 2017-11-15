#ifndef BLINDUI_H
#define BLINDUI_H
#include "blind.h"


class BlindUI
{
    Blind* blind;
public:
    BlindUI();
    Blind *getBlind() const;
    void setBlind(Blind *value);
};

#endif // BLINDUI_H
