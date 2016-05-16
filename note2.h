#ifndef NOTE2_H
#define NOTE2_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class note2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    note2();
    void storePointerAddressInUI(note2 **address);
    void remove();

public slots:
    void move();

private:
    QTimer *timer;
    note2 **pointerAddressInUI;
};

#endif // NOTE2_H
