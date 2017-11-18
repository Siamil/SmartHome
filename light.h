#ifndef LIGHT_H
#define LIGHT_H


class Light
{
    bool isTurned;
public:
    Light();

    bool getIsTurned() const;
    void setIsTurned(bool value);
};

#endif // LIGHT_H
