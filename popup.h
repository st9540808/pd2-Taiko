#ifndef POPUP_H
#define POPUP_H

#include <QDialog>

namespace Ui {
class popup;
}

class popup : public QDialog
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = 0);
    ~popup();
    void updataData(int *score);

signals:
    void restartGame();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::popup *ui;
};

#endif // POPUP_H
