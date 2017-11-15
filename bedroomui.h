#ifndef BEDROOMUI_H
#define BEDROOMUI_H

#include <QWidget>
#include "room.h"

class BedroomUI : public QWidget
{
    Q_OBJECT
    Room* room;
public:
    explicit BedroomUI(QWidget *parent = 0);
    void drawFrame(QPainter *painter);
    void drawWindows(QPainter *painter);
    BedroomUI(Room* room);



    Room *getRoom() const;
    void setRoom(Room *value);

signals:

public slots:
};

#endif // BEDROOMUI_H
