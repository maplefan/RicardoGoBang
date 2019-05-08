#include "dialoggameover.h"
#include "ui_dialoggameover.h"

DialogGameOver::DialogGameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameOver)
{
    ui->setupUi(this);
}

DialogGameOver::~DialogGameOver()
{
    delete ui;
}

void DialogGameOver::setLabelText(QString str)
{
    this->ui->label_gameover->setText(str);
}
