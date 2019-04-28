#ifndef PVMWINDOW_H
#define PVMWINDOW_H

#include <QMainWindow>
#include <dialogabout.h>
#include <chess.h>

namespace Ui {
class PVMWindow;
}

class PVMWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PVMWindow(QWidget *parent = 0);
    ~PVMWindow();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private slots:

    void on_btn_back_clicked();

    void on_btn_about_clicked();

private:
    Ui::PVMWindow *ui;
};

#endif // PVMWINDOW_H
