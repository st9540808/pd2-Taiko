#include "note.h"
#include <QDebug>

note::note()
{
    setPixmap(QPixmap(":/image/don.png"));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(4);
}

void note::storePointerAddressInUI(note **address)
{
    pointerAddressInUI = address;
    //    qDebug() << "address stored";
}

void note::remove()
{
    *pointerAddressInUI = NULL;

    timer->stop();
    scene()->removeItem(this);
    delete timer;
    delete this;
    return;
}

void note::move()
{
    setPos(x()-1, y());
    if( pos().x() + 50 < 0 )
    {
        *pointerAddressInUI = NULL;

//       qDebug() << "address reset to NULL";
        timer->stop();
        scene()->removeItem(this);
        delete timer;
        delete this;
        return;
//        qDebug() << "note deleted";
   }
}


