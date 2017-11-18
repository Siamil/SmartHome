#ifndef DOOR_H
#define DOOR_H


class Door
{
    bool open = true;
public:
    Door();
    bool getOpen() const;
    void setOpen(bool value);
};

#endif // DOOR_H
