#ifndef HEAT_H
#define HEAT_H


class Heat
{
    bool isTurned = true;
public:
    Heat();

    bool getIsTurned() const;
    void setIsTurned(bool value);
};

#endif // HEAT_H
