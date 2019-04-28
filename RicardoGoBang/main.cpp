#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("RicardoGoBang");


    w.show();//显示窗体
    return a.exec();
}
