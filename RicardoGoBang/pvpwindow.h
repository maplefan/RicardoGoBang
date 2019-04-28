#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <dialogabout.h>
#include <chess.h>

namespace Ui {
class PVPWindow;
}

class PVPWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PVPWindow(QWidget *parent = 0);
    ~PVPWindow();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

private slots:

    void on_btn_about_clicked();

    void on_btn_back_clicked();

private:
    Ui::PVPWindow *ui;
};

#endif // PVPWINDOW_H
