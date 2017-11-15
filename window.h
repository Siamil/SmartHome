#ifndef WINDOW_H
#define WINDOW_H


class Window
{
    bool open = true;
public:
    Window();


    bool getOpen() const;
    void setOpen(bool value);
};

#endif // WINDOW_H
