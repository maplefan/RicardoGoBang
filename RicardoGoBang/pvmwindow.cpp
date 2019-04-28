#include "pvmwindow.h"
#include "ui_pvmwindow.h"

PVMWindow::PVMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVMWindow)
{
    ui->setupUi(this);
    Chess *chess = new Chess(ui->widget_chess);
}

PVMWindow::~PVMWindow()
{
    delete ui;
}

void PVMWindow::on_btn_back_clicked()
{
    emit sendsignal();
        this->close();
}

void PVMWindow::on_btn_about_clicked()
{
    DialogAbout *dialogAbout = new DialogAbout(this);
    dialogAbout->show();
}
