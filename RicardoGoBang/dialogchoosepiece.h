#ifndef DIALOGCHOOSEPIECE_H
#define DIALOGCHOOSEPIECE_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class DialogChoosePiece;
}

class DialogChoosePiece : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChoosePiece(QWidget *parent = 0);
    ~DialogChoosePiece();
    bool getWhoFirst();
    bool getPlayer1Use();

private slots:
    void on_buttonBox_accepted();

signals:
    void restart_emit();

private:
    Ui::DialogChoosePiece *ui;
    QButtonGroup *groupButtonWhoFirst;
    QButtonGroup *groupButtonPlayer1Piece;
    bool whoFirst = false;
    bool player1Use = false;
};

#endif // DIALOGCHOOSEPIECE_H
