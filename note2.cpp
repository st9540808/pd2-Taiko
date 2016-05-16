#include "note2.h"

note2::note2()
{
    setPixmap(QPixmap(":/image/kat.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(4);
}

void note2::storePointerAddressInUI(note2 **address)
{
    pointerAddressInUI = address;
}

void note2::remove()
{
    *pointerAddressInUI = NULL;

    timer->stop();
    scene()->removeItem(this);
    delete timer;
    delete this;
    return;
}

void note2::move()
{
    setPos(x()-1, y());
    if( pos().x() + 50 < 0 )
    {
        *pointerAddressInUI = NULL;

        timer->stop();
        scene()->removeItem(this);
        delete timer;
        delete this;
        return;
   }
}

