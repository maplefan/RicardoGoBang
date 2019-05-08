#include "chess.h"
#include "ui_chess.h"
#include "pvpwindow.h"


int countWhoFirst;
int countPlayer1Use = -1;
int gameMode;
extern bool gameState;
extern void gameover(int, int);

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess)
{
    ui->setupUi(this);
    //初始化为0，1为白子，-1为黑子。
    //memeset函数只能对连续的内存空间初始化，new在堆上分的内存可能会不连续。
    for(int i = 0; i <15;i++){
        for(int j = 0; j<15 ;j++){
            chessBoard[i][j] = 0;
        }
    }
    setMouseTracking(true);
    step = 0;//步数初始化为0
    whoWin = 0;//赢家判断标志初始化为0

}

Chess::~Chess()
{
    delete ui;
    countWhoFirst = 0;
}

void Chess::paintEvent(QPaintEvent *)//绘制事件
{
    QPainter *paint=new QPainter;
    paint->begin(this);//开始绘制
    paint->setRenderHint(QPainter::Antialiasing, true);//抗锯齿
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
    paint->fillRect(QRect(10,10,590,590), QBrush(QColor(215,156,80)));


    //绘制棋盘线条
    for(int i = 0;i<15;i++){
        paint->drawLine(25+40*i,25,25+40*i,585);
    }
    for(int i = 0;i<15 ;i++){
        paint->drawLine(25,25+40*i,585,25+40*i);
    }

    //绘制五个棋盘黑点
    QBrush  *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(Qt::black);
    paint->setBrush(*brush);
    paint->drawRect(140,140,10,10);
    paint->drawRect(460,460,10,10);
    paint->drawRect(140,460,10,10);
    paint->drawRect(460,140,10,10);
    paint->drawRect(300,300,10,10);

    //test
    /*
    chessBoard[0][0] = -1;
    chessBoard[8][8] = 1;
    chessBoard[11][8] = 1;
    chessBoard[14][8] = 1;
    chessBoard[7][2] = 1;*/

    //绘制棋子
    for(int i = 0; i < 15;i++){
        for(int j = 0; j< 15 ;j++){
            if(chessBoard[i][j] == -1){//黑子
                brush->setColor(Qt::black);
                paint->setPen(Qt::NoPen);
                paint->setBrush(*brush);
                paint->drawEllipse(11+i*40,11+j*40,28,28);
            }
            else if(chessBoard[i][j] == 1){//白子
                brush->setColor(Qt::white);
                paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
                paint->setBrush(*brush);
                paint->drawEllipse(11+i*40,11+j*40,28,28);
            }
        }
    }
    QPen *pen = new QPen(Qt::red);
    pen->setWidth(2);
    paint->setPen(*pen);
    if(step!=0){
        paint->drawLine(preX*40+25-10,preY*40+25,preX*40+25+10,preY*40+25);
        paint->drawLine(preX*40+25,preY*40+25-10,preX*40+25,preY*40+25+10);
    }


    if(moveX*40+25 >=20 && moveX*40 +25 <= 600 && moveY*40+25 >=20 && moveY*40 +25 <= 600 && getChessBoard(moveX,moveY)==0){

        // paint->drawRect(moveX*40+25-15,moveY*40+25-15,30,30);
        paint->drawLine(moveX*40+25-15,moveY*40+25-15,moveX*40+25-5,moveY*40+25-15);
        paint->drawLine(moveX*40+25-15,moveY*40+25-15,moveX*40+25-15,moveY*40+25-5);
        paint->drawLine(moveX*40+25+15,moveY*40+25+15,moveX*40+25+5,moveY*40+25+15);
        paint->drawLine(moveX*40+25+15,moveY*40+25+15,moveX*40+25+15,moveY*40+25+5);

        paint->drawLine(moveX*40+25-15,moveY*40+25+15,moveX*40+25-5,moveY*40+25+15);
        paint->drawLine(moveX*40+25-15,moveY*40+25+15,moveX*40+25-15,moveY*40+25+5);
        paint->drawLine(moveX*40+25+15,moveY*40+25-15,moveX*40+25+5,moveY*40+25-15);
        paint->drawLine(moveX*40+25+15,moveY*40+25-15,moveX*40+25+15,moveY*40+25-5);
    }


    paint->end();//结束绘制

}

void Chess::mouseMoveEvent(QMouseEvent *event) {
    moveX = (event->x()-5)/40;
    moveY = (event->y()-5)/40;
    update();
}

void Chess::mouseReleaseEvent(QMouseEvent* event){
    if(gameState == true){
        moveX = (event->x()-5)/40;
        moveY = (event->y()-5)/40;
        if(chessBoard[moveX][moveY] == 0){
            if(gameMode == 1){//pvp
                if((step + countWhoFirst )%2 == 0){
                    //黑子回合
                    step++;
                    chessBoard[moveX][moveY] = -1;
                    addChessBoardXY(moveX,moveY);
                    emit start_emit(step);
                    preX = moveX;
                    preY = moveY;
                    if(isWin(moveX,moveY)== true){//满足胜利条件
                        if(countPlayer1Use == 0){//玩家1是黑色
                            whoWin = 1;//玩家1获胜
                        }
                        else whoWin = 2;//玩家2获胜
                        qDebug("%d %d",gameMode,whoWin);
                         gameOver(gameMode,whoWin);
                    }
                }
                else{
                    //白子回合
                    step++;
                    chessBoard[moveX][moveY] = 1;
                    addChessBoardXY(moveX,moveY);
                    emit start_emit(step);
                    preX = moveX;
                    preY = moveY;
                    if(isWin(moveX,moveY)== true){//满足胜利条件
                        if(countPlayer1Use == 0){//玩家1是黑色
                            whoWin = 2;//玩家2获胜
                        }
                        else whoWin = 1;//玩家1获胜
                        qDebug("%d %d",gameMode,whoWin);
                        gameOver(gameMode,whoWin);
                    }
                }
                update();
            }
            else if(gameMode == 2){//pvm

            }
        }
    }
}



int Chess::getChessBoard(int x,int y){
    return chessBoard[x][y];
}

void Chess::setChessBoard(int x,int y,int value){
    if(x >= 0 && x < 15 && y >= 0 && y < 15 && value<=1 && value >= -1){
        chessBoard[x][y] = value;
    }
}

bool Chess:: deleteChessBoardXY(){
    if(chessBoardX.empty()  || chessBoardY.empty()){
        return false;
    }
    else{
        chessBoard[chessBoardX.back()][chessBoardY.back()] = 0;
        step--;
        emit start_emit(step);
        chessBoardX.pop_back();
        chessBoardY.pop_back();
        preX = chessBoardX.back();
        preY = chessBoardY.back();
        return true;
    }
}

void Chess::clearChessBoard(){
    chessBoardX.clear();
    chessBoardY.clear();
    for(int i = 0; i < 15 ;i++){
        for(int j = 0; j < 15 ;j++){
            setChessBoard(i,j,0);
        }
    }
    step = 0;
}

void Chess::addChessBoardXY(int x,int y){
    chessBoardX.push_back(x);
    chessBoardY.push_back(y);
}

void Chess::setStep(int step){
    this->step = step;
}

int Chess::getStep(){
   return this->step;
}

void Chess::setWhoWin(int num){
   this->whoWin = num;
}

bool Chess::isWin(int row, int col)
{
    // 横竖斜四种大情况，每种情况都根据当前落子往后遍历5个棋子，有一种符合就算赢
    // 水平方向
    for (int i = 0; i < 5; i++)
    {
        // 往左5个，往右匹配4个子，20种情况
        if (col - i >= 0 &&
            col - i + 4 < 15 &&
            getChessBoard(row,col - i) == getChessBoard(row,col - i + 1) &&
            getChessBoard(row,col - i) == getChessBoard(row,col - i + 2) &&
            getChessBoard(row,col - i) == getChessBoard(row,col - i + 3) &&
            getChessBoard(row,col - i) == getChessBoard(row,col - i + 4))
            return true;
    }

    // 竖直方向(上下延伸4个)
    for (int i = 0; i < 5; i++)
    {
        if (row - i >= 0 &&
            row - i + 4 < 15 &&
            getChessBoard(row - i,col) == getChessBoard(row - i + 1,col) &&
            getChessBoard(row - i,col) == getChessBoard(row - i + 2,col) &&
            getChessBoard(row - i,col) == getChessBoard(row - i + 3,col) &&
            getChessBoard(row - i,col) == getChessBoard(row - i + 4,col))
            return true;
    }

    // 左斜方向
    for (int i = 0; i < 5; i++)
    {
        if (row + i <15 &&
            row + i - 4 >= 0 &&
            col - i >= 0 &&
            col - i + 4 < 15 &&
            getChessBoard(row + i,col - i) == getChessBoard(row + i - 1,col - i + 1) &&
            getChessBoard(row + i,col - i) == getChessBoard(row + i - 2,col - i + 2) &&
            getChessBoard(row + i,col - i) == getChessBoard(row + i - 3,col - i + 3) &&
            getChessBoard(row + i,col - i) == getChessBoard(row + i - 4,col - i + 4))
            return true;
    }

    // 右斜方向
    for (int i = 0; i < 5; i++)
    {
        if (row - i >= 0 &&
            row - i + 4 < 15 &&
            col - i >= 0 &&
            col - i + 4 < 15 &&
            getChessBoard(row - i,col - i) == getChessBoard(row - i + 1,col - i + 1) &&
            getChessBoard(row - i,col - i) == getChessBoard(row - i + 2,col - i + 2) &&
            getChessBoard(row - i,col - i) == getChessBoard(row - i + 3,col - i + 3) &&
            getChessBoard(row - i,col - i) == getChessBoard(row - i + 4,col - i + 4))
            return true;
    }

    return false;
}

void Chess::gameOver(int gameMode , int whoWin){
    if(whoWin == 1){
        //玩家1胜利
        if(gameMode == 1){//pvp
            DialogGameOver *dialogGameOver = new DialogGameOver(this);
            dialogGameOver->setLabelText(QString("玩家1获胜！"));
            dialogGameOver->show();
        }
        else if(gameMode == 2){//pvm

        }
    }
    else if(whoWin == 2){
        //玩家2胜利
        if(gameMode == 1){//pvp
            DialogGameOver *dialogGameOver = new DialogGameOver(this);
            dialogGameOver->setLabelText(QString("玩家2获胜！"));
            dialogGameOver->show();
        }
        else if(gameMode == 2){//pvm

        }
    }
    else if(whoWin == 3){
        //平局
        DialogGameOver *dialogGameOver = new DialogGameOver();
        dialogGameOver->setLabelText(QString("平局！"));
    }
    gameState = false;
}


