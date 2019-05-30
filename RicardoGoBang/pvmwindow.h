#ifndef PVMWINDOW_H
#define PVMWINDOW_H

#include <QMainWindow>
#include <dialogabout.h>
#include <dialogchoosepiece.h>
#include <chess.h>
#include <game.h>

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

    void read_emit(int,int,int);

    void on_btn_back_clicked();

    void on_btn_about_clicked();

    void on_btn_start_clicked();

    void restartGame();

    void on_btn_undo_clicked();

    void on_btn_giveup_clicked();

private:
    Ui::PVMWindow *ui;
    Chess *chess;
        void paintEvent(QPaintEvent *);
};

#endif // PVMWINDOW_H
