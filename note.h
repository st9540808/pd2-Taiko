#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class note : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    note();
    void storePointerAddressInUI(note **address);
    void remove();

public slots:
    void move();

private:
    QTimer *timer;
    note **pointerAddressInUI;

};

#endif // NOTE_H
