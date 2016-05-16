#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
}

popup::~popup()
{
    delete ui;
}

void popup::updataData(int *score)
{
    ui->lcdNumber->display(*score);
}

void popup::on_pushButton_2_clicked()
{
    exit(0);
}

void popup::on_pushButton_clicked()
{
    emit restartGame();
    delete this;
}
