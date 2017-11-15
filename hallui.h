#ifndef HALLUI_H
#define HALLUI_H

#include <QWidget>
#include <room.h>


class HallUI : public QWidget
{
    Q_OBJECT
    Room* room;
public:
    explicit HallUI(QWidget *parent = 0);
    HallUI(Room* room);
    void drawFrame(QPainter *painter);
    void drawWindows(QPainter *painter);


    Room *getRoom() const;
    void setRoom(Room *value);

signals:

public slots:
};

#endif // HALLUI_H
