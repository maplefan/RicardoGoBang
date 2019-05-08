#ifndef DIALOGGAMEOVER_H
#define DIALOGGAMEOVER_H

#include <QDialog>

namespace Ui {
class DialogGameOver;
}

class DialogGameOver : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGameOver(QWidget *parent = 0);
    ~DialogGameOver();
    void setLabelText(QString str);

private:
    Ui::DialogGameOver *ui;
};

#endif // DIALOGGAMEOVER_H
