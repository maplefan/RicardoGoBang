#ifndef PVPWINDOW_H
#define PVPWINDOW_H

#include <QMainWindow>
#include <dialogabout.h>
#include <dialogchoosepiece.h>
#include <chess.h>
#include <game.h>

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

    void read_emit(int,int,int);

    void restartGame();

    void on_btn_about_clicked();

    void on_btn_back_clicked();

    void on_btn_start_clicked();

    void on_btn_undo_clicked();

    void on_btn_giveup_clicked();

private:
    Ui::PVPWindow *ui;
    Chess *chess;
    void paintEvent(QPaintEvent *);
};

#endif // PVPWINDOW_H
