#include "pvpwindow.h"
#include "ui_pvpwindow.h"

PVPWindow::PVPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVPWindow)
{
    ui->setupUi(this);
    Chess *chess = new Chess(ui->widget_chess);
}

PVPWindow::~PVPWindow()
{
    delete ui;
}

void PVPWindow::on_btn_about_clicked()
{
    DialogAbout *dialogAbout = new DialogAbout(this);
    dialogAbout->show();
}

void PVPWindow::on_btn_back_clicked()
{
    emit sendsignal();
        this->close();
}
