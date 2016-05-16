#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QBrush>
#include <QImage>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    noteIntervalTimer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(countDown()));
    connect(noteIntervalTimer, SIGNAL(timeout()), this, SLOT(creatNote()));
    countDownTime = 30;
    score = 0;

    gameEndScreen = new popup;
    connect(this, SIGNAL(gameTimeUp()), gameEndScreen, SLOT(exec()));
    connect(gameEndScreen, SIGNAL(restartGame()), this, SLOT(restart()));

    for(int i = 0; i < 100; ++i)
    {
        noteMemoryAddress[i] = NULL;
        note2MemoryAddress[i] = NULL;
    }
    currentNoteNumber = 0;
    currentNote2Number = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameStart()
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(this);
    scene->setSceneRect(0,0,751,110);
    scene->setBackgroundBrush(QBrush(QImage(":/image/background.png")));
//    setBackgroundBrush();

    view->setScene(scene);
    view->setFixedSize(751,110);

    view->setGeometry(QRect(0,142,751,110));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    Target *target = new Target;
    target->setPos(20,20);
    scene->addItem(target);
}


void MainWindow::countDown()
{
    if( countDownTime < 0 )
    {
        timer->stop();
        gameEndScreen->updataData(&score);
        emit gameTimeUp();
    }
    else if( countDownTime == 2 )
    {
        noteIntervalTimer->stop();
        ui->timerLcd->display(countDownTime--);
    }
    else
    ui->timerLcd->display(countDownTime--);
}

void MainWindow::creatNote()
{
    int randomNum = rand() % 2;

    switch(randomNum)
    {
    case 0:
        {
        note *newNote = new note;
        newNote->setPos(751,30);
        scene->addItem(newNote);

        noteMemoryAddress[currentNoteNumber] = newNote;
        newNote->storePointerAddressInUI( &noteMemoryAddress[currentNoteNumber] );
        currentNoteNumber++;
        break;
        }
    case 1:
        {
        note2 *newNote2 = new note2;
        newNote2->setPos(751,30);
        scene->addItem(newNote2);

        note2MemoryAddress[currentNote2Number] = newNote2;
        newNote2->storePointerAddressInUI( &note2MemoryAddress[currentNote2Number] );
        currentNote2Number++;
        break;
        }
    }
}

void MainWindow::restart()
{
    gameEndScreen = new popup;
    connect(this, SIGNAL(gameTimeUp()), gameEndScreen, SLOT(exec()));
    connect(gameEndScreen, SIGNAL(restartGame()), this, SLOT(restart()));

    for(int i = 0; i < 100; ++i)
    {
        noteMemoryAddress[i] = NULL;
        note2MemoryAddress[i] = NULL;
    }
    currentNoteNumber = 0;
    currentNote2Number = 0;

    countDownTime = 30;
    score = 0;

    timer->start(1000);
    noteIntervalTimer->start(800);
    gameStart();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_J )
    {
        for(int i = 0; i < 100; ++i)
            if( noteMemoryAddress[i] != NULL )
            {
                if( noteMemoryAddress[i]->pos().x() + 25 < 90 &&
                    noteMemoryAddress[i]->pos().x() + 25 > 20)
                {
                    noteMemoryAddress[i]->remove();
                    ui->score->display(++score);
                    return;
                }
            }
    }
    if( event->key() == Qt::Key_K )
    {
        for(int i = 0; i < 100; ++i)
            if( note2MemoryAddress[i] != NULL )
            {
                if( note2MemoryAddress[i]->pos().x() + 25 < 90 &&
                    note2MemoryAddress[i]->pos().x() + 25 > 20)
                {
                    note2MemoryAddress[i]->remove();
                    ui->score->display(++score);
                    return;
                }
            }
    }
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(1000);
    noteIntervalTimer->start(800);
    gameStart();
}
