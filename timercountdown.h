#ifndef TIMERCOUNTDOWN_H
#define TIMERCOUNTDOWN_H
#include <QObject>
#include <QTimer>

class timerCountDown : public QObject
{
    Q_OBJECT

public:
    timerCountDown();
    QTimer *timer;
    int countDownTime;

public slots:
    void countDown();

signals:


};

#endif // TIMERCOUNTDOWN_H
