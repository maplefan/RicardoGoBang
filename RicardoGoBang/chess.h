#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include <QPainter>
#include <QPen>
namespace Ui {
class Chess;
}

class Chess : public QWidget
{
    Q_OBJECT

public:
    explicit Chess(QWidget *parent = 0);
    ~Chess();

private:
    Ui::Chess *ui;
    void paintEvent(QPaintEvent *);
};

#endif // CHESS_H
