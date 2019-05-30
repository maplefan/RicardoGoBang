#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <game.h>
#include <vector>
#include <dialoggameover.h>
#include <chessengine.h>

namespace Ui {
class Chess;
}

class Chess : public QWidget
{
    Q_OBJECT

public:
    explicit Chess(QWidget *parent = 0);
    ~Chess();

    void send_emit();
    int getChessBoard(int x,int y);
    void setChessBoard(int x,int y,int value);
    bool deleteChessBoardXY();
    void addChessBoardXY(int x,int y);
    void clearChessBoard();
    void setStep(int step);
    int getStep();
    void setWhoWin(int);
    bool isWin(int row, int col);
    void gameOver(int ,int);

signals:
    void start_emit(int,int,int);

private:
    Ui::Chess *ui;
    int whoWin;
    int moveX,moveY;
    int preX,preY;//上一步
    int step ;//步数
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    std::vector<int>chessBoardX;//记录步数的X
    std::vector<int>chessBoardY;//记录步数的Y

};

#endif // CHESS_H
