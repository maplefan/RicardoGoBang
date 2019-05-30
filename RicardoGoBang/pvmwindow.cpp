#include "pvmwindow.h"
#include "ui_pvmwindow.h"
#include<QDebug>
extern bool gameState;
extern int gameMode;
extern int countWhoFirst;
extern int countPlayer1Use;
extern bool isFirstStep;

PVMWindow::PVMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PVMWindow)
{
    ui->setupUi(this);
    Chess *chess = new Chess(ui->widget_chess);
    this->chess = chess;
    isFirstStep = true;
    gameMode = 2;
    connect(chess,SIGNAL(start_emit(int,int,int)),this,SLOT(read_emit(int,int,int)));
}

PVMWindow::~PVMWindow()
{
    delete ui;
}

void PVMWindow::on_btn_back_clicked()
{
    gameState = false;
    countPlayer1Use = -1;
    emit sendsignal();
        this->close();
    isFirstStep = true;
}

void PVMWindow::on_btn_about_clicked()
{
    DialogAbout *dialogAbout = new DialogAbout(this);
    dialogAbout->show();
}

void PVMWindow::on_btn_start_clicked()
{
    DialogChoosePiece *dialog = new DialogChoosePiece(this);
    dialog->show();
    connect(dialog,SIGNAL(restart_emit()),this,SLOT(restartGame()));
}

void PVMWindow::restartGame(){
    this->chess->clearChessBoard();
    this->chess->setWhoWin(0);
    this->ui->label_step->setText(QString("STEP： ")+QString::number(this->chess->getStep(),10)+QString(" 步"));
    this->ui->btn_start->setText("重新开始");
    isFirstStep = true;
    gameState = true;
    if(gameMode == 2){
        if(countWhoFirst == 0 && countPlayer1Use == 1){//黑子先手 白子玩家
             ChessEngine::reset(1);
             this->chess->setStep(1);
             read_emit(1,0,0);
        }
        else if(countWhoFirst == 1 && countPlayer1Use == 0){//白子先手 黑子玩家
             ChessEngine::reset(1);
             this->chess->setStep(1);
             read_emit(1,0,0);
        }
        else{
            ChessEngine::reset(0);
            this->chess->setStep(0);
            read_emit(0,0,0);
        }
    }
}

void PVMWindow::paintEvent(QPaintEvent *)//绘制事件
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

void PVMWindow::on_btn_undo_clicked()//人机模式悔棋悔两步，一步玩家一步电脑
{
    gameState = true;
    ChessEngine::takeBack();
    this->chess->deleteChessBoardXY();
    update();
}

void PVMWindow::on_btn_giveup_clicked()
{
    isFirstStep = true;
    if(gameMode == 2){
        this->chess->gameOver(gameMode,2);
    }
    else if((this->chess->getStep()+ countWhoFirst )%2 == 0){//黑子回合弃权
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

void PVMWindow::read_emit(int num ,int score1 ,int score2){
    QString str = QString("STEP： ")+QString::number(num,10)+QString(" 步");

    QString score = QString("局势得分：\n黑子：白子 = ")+QString::number(score1,10) + QString(" : ") +QString::number(score2,10);
    ui->label_step->setText(str);
    ui->label_rate->setText(score);
}
