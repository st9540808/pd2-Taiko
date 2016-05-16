#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "popup.h"
#include "note.h"
#include "note2.h"
#include "target.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void gameStart();

signals:
    void gameTimeUp();

public slots:
    void countDown();
    void creatNote();
    void restart();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer, *noteIntervalTimer;
    popup *gameEndScreen;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int countDownTime;
    int score;

    note  *noteMemoryAddress[100];
    note2 *note2MemoryAddress[100];
    int currentNoteNumber;
    int currentNote2Number;
};

#endif // MAINWINDOW_H
