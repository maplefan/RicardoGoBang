#include "pvpwindow.h"
#include "ui_pvpwindow.h"

extern bool gameState;
extern int countWhoFirst;
extern int countPlayer1Use;
extern int gameMode;

PVPWindow::PVPWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVPWindow)
{
    ui->setupUi(this);
    Chess *chess = new Chess(ui->widget_chess);
    this->chess = chess;
    gameMode = 1;
    connect(chess,SIGNAL(start_emit(int)),this,SLOT(read_emit(int)));
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
    gameState = false;
    countPlayer1Use = -1;
    emit sendsignal();
        this->close();
}

void PVPWindow::on_btn_start_clicked()
{
      gameState = true;
      DialogChoosePiece *dialog = new DialogChoosePiece(this);
      dialog->show();
      connect(dialog,SIGNAL(restart_emit()),this,SLOT(restartGame()));
}

void PVPWindow::on_btn_undo_clicked()
{
    gameState = true;
       this->chess->deleteChessBoardXY();
    update();
}

void PVPWindow::read_emit(int num){
    QString str = QString("STEP： ")+QString::number(num,10)+QString(" 步");
    ui->label_step->setText(str);
}

void PVPWindow::restartGame(){
    this->chess->clearChessBoard();
    this->chess->setWhoWin(0);
    this->ui->label_step->setText(QString("STEP： ")+QString::number(this->chess->getStep(),10)+QString(" 步"));
    this->ui->btn_start->setText("重新开始");
}

void PVPWindow::on_btn_giveup_clicked()
{
    if((this->chess->getStep()+ countWhoFirst )%2 == 0){//黑子回合弃权
        if(countPlayer1Use == 0){//玩家1是黑子
            this->chess->gameOver(gameMode,2);
        }
        else if(countPlayer1Use == 1){//玩家1是白子
            this->chess->gameOver(gameMode,1);
        }
    }
    else if((this->chess->getStep() + countWhoFirst )%2 == 1){//白子回合弃权
        if(countPlayer1Use == 0){//玩家1是黑子
            this->chess->gameOver(gameMode,1);
        }
        else if(countPlayer1Use == 1){//玩家1是白子
            this->chess->gameOver(gameMode,2);
        }
    }
}

void PVPWindow::paintEvent(QPaintEvent *)//绘制事件
{
    QPainter *paint=new QPainter;
    paint->begin(this);//开始绘制
    paint->setRenderHint(QPainter::Antialiasing, true);//抗锯齿
    paint->setPen(Qt::NoPen);
    QBrush  *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);

    if(countPlayer1Use == 0){
        brush->setColor(Qt::black);
        paint->setBrush(*brush);
        paint->drawEllipse(625,180,28,28);

        brush->setColor(Qt::white);
        paint->setBrush(*brush);
        paint->drawEllipse(725,180,28,28);

    }
    else if(countPlayer1Use == 1){
        brush->setColor(Qt::white);
        paint->setBrush(*brush);
        paint->drawEllipse(625,180,28,28);

        brush->setColor(Qt::black);
        paint->setBrush(*brush);
        paint->drawEllipse(725,180,28,28);
    }
    paint->end();
}
