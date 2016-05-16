#include "timercountdown.h"


timerCountDown::timerCountDown()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(countDown()));
    timer->start(1000);

    countDownTime = 60;
}
