#include "chess.h"
#include "ui_chess.h"
#include "pvpwindow.h"
#include <iostream>
using namespace std;

int isover;
int myturn;
int backnum,whitenum;
int preWx,preWy;
int preBx,preBy;
bool winFlag = false;
int countWhoFirst = -1;
int countPlayer1Use = -1;
bool isFirstStep = true;
int gameMode;
extern bool gameState;
extern void gameover(int, int);
int chessBoard[15][15];//棋盘
vector<int>score1;
vector<int>score2;

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess)
{
    ui->setupUi(this);
    //初始化为0，1为白子，2为黑子。
    //memeset函数只能对连续的内存空间初始化，new在堆上分的内存可能会不连续。
    for(int i = 0; i <15;i++){
        for(int j = 0; j<15 ;j++){
            chessBoard[i][j] = 0;
        }
    }
    cout<<"haha";
    setMouseTracking(true);
    step = 0;//步数初始化为0
    whoWin = 0;//赢家判断标志初始化为0
    ChessEngine::beforeStart();
    ChessEngine::setLevel(9);
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
    chessBoard[0][0] = 2;
    chessBoard[8][8] = 1;
    chessBoard[11][8] = 1;
    chessBoard[14][8] = 1;
    chessBoard[7][2] = 1;*/

    //绘制棋子
    if(gameMode == 1){
        for(int i = 0; i < 15;i++){
            for(int j = 0; j< 15 ;j++){
                if(chessBoard[i][j] == 2){//黑子
                    brush->setColor(Qt::black);
                    paint->setPen(Qt::NoPen);
                    paint->setBrush(*brush);
                    paint->drawEllipse(11+j*40,11+i*40,28,28);
                }
                else if(chessBoard[i][j] == 1){//白子
                    brush->setColor(Qt::white);
                    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
                    paint->setBrush(*brush);
                    paint->drawEllipse(11+j*40,11+i*40,28,28);
                }
            }
        }
    }
    else if(gameMode == 2){
        if((countWhoFirst == 0 && countPlayer1Use == 0)||(countWhoFirst == 1 && countPlayer1Use == 0)){
            for(int i = 0; i < 15;i++){
                for(int j = 0; j< 15 ;j++){
                    if(chessBoard[i][j] == 1){//黑子
                        brush->setColor(Qt::black);
                        paint->setPen(Qt::NoPen);
                        paint->setBrush(*brush);
                        paint->drawEllipse(11+j*40,11+i*40,28,28);
                    }
                    else if(chessBoard[i][j] == 2){//白子
                        brush->setColor(Qt::white);
                        paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
                        paint->setBrush(*brush);
                        paint->drawEllipse(11+j*40,11+i*40,28,28);
                    }
                }
            }
        }
        else{
            for(int i = 0; i < 15;i++){
                for(int j = 0; j< 15 ;j++){
                    if(chessBoard[i][j] == 2){//黑子
                        brush->setColor(Qt::black);
                        paint->setPen(Qt::NoPen);
                        paint->setBrush(*brush);
                        paint->drawEllipse(11+j*40,11+i*40,28,28);
                    }
                    else if(chessBoard[i][j] == 1){//白子
                        brush->setColor(Qt::white);
                        paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
                        paint->setBrush(*brush);
                        paint->drawEllipse(11+j*40,11+i*40,28,28);
                    }
                }
            }
        }
    }
    QPen *pen = new QPen(Qt::red);
    pen->setWidth(2);
    paint->setPen(*pen);
    if(step!=0){
        paint->drawLine(preY*40+25-10,preX*40+25,preY*40+25+10,preX*40+25);
        paint->drawLine(preY*40+25,preX*40+25-10,preY*40+25,preX*40+25+10);
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
        moveY = (event->x()-5)/40;
        moveX = (event->y()-5)/40;
        if(chessBoard[moveX][moveY] == 0){
            if(gameMode == 1){//pvp
                if((step + countWhoFirst )%2 == 0){
                    //黑子回合
                    step++;
                    chessBoard[moveX][moveY] = 2;
                    cout<<moveX<<" "<<moveY<<endl;
                    addChessBoardXY(moveX,moveY);
                    emit start_emit(step,0,0);
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
                    else if(step == 255){//平局
                        gameOver(gameMode,3);
                    }
                }
                else{
                    //白子回合
                    step++;
                    chessBoard[moveX][moveY] = 1;
                    cout<<moveX<<" "<<moveY<<endl;
                    addChessBoardXY(moveX,moveY);
                    emit start_emit(step,0,0);
                    if(isWin(moveX,moveY)== true){//满足胜利条件
                        if(countPlayer1Use == 0){//玩家1是黑色
                            whoWin = 2;//玩家2获胜
                        }
                        else whoWin = 1;//玩家1获胜
                        qDebug("%d %d",gameMode,whoWin);
                        gameOver(gameMode,whoWin);
                    }
                    else if(step == 255){//平局
                        gameOver(gameMode,3);
                    }
                    preX = moveX;
                    preY = moveY;
                }
                update();
            }
            else if(gameMode == 2){//pvm
                if(countWhoFirst  == 0){//黑子先手，黑子玩家
                    if(countPlayer1Use == 0){
                        chessBoard[moveX][moveY] = 1;
                        addChessBoardXY(moveX,moveY);
                        step++;
                        emit start_emit(step,ChessEngine::evaluate(chessBoard,1),ChessEngine::evaluate(chessBoard,2));
                        score1.push_back(ChessEngine::evaluate(chessBoard,1));
                        score2.push_back(ChessEngine::evaluate(chessBoard,2));
                        repaint();
                        if(isWin(moveX,moveY)== true){//满足胜利条件
                            whoWin = 1;//玩家获胜
                            qDebug("%d %d",gameMode,whoWin);
                            gameOver(gameMode,whoWin);

                        }
                        else if(step == 255){//平局
                            gameOver(gameMode,3);
                        }

                        qDebug("score:%d",ChessEngine::evaluate(chessBoard,1));
                        if(gameState){
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            ChessEngine::nextStep(moveX,moveY);
                            chessBoard[moveX][moveY] = 2;
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            step++;
                            addChessBoardXY(moveX,moveY);
                            emit start_emit(step,ChessEngine::evaluate(chessBoard,1),ChessEngine::evaluate(chessBoard,2));
                            score1.push_back(ChessEngine::evaluate(chessBoard,1));
                            score2.push_back(ChessEngine::evaluate(chessBoard,2));
                            if(isWin(moveX,moveY)== true){//满足胜利条件
                                whoWin = 2;//电脑获胜
                                qDebug("%d %d",gameMode,whoWin);
                                gameOver(gameMode,whoWin);
                            }
                            else if(step == 255){//平局
                                gameOver(gameMode,3);
                            }
                        }
                        qDebug("score:%d",ChessEngine::evaluate(chessBoard,2));
                        preX = moveX;
                        preY = moveY;
                    }

                    else if(countPlayer1Use == 1){//黑子先手 白子玩家
                        qDebug("sssssscore:%d",countPlayer1Use);
                        chessBoard[moveX][moveY] = 1;
                        addChessBoardXY(moveX,moveY);
                        step++;
                        emit start_emit(step,ChessEngine::evaluate(chessBoard,2),ChessEngine::evaluate(chessBoard,1));
                        score1.push_back(ChessEngine::evaluate(chessBoard,1));
                        score2.push_back(ChessEngine::evaluate(chessBoard,2));
                        repaint();
                        if(isWin(moveX,moveY)== true){//满足胜利条件
                            whoWin = 1;//玩家获胜
                            qDebug("%d %d",gameMode,whoWin);
                            gameOver(gameMode,whoWin);
                        }
                        else if(step == 255){//平局
                            gameOver(gameMode,3);
                        }

                        if(gameState){
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            ChessEngine::nextStep(moveX,moveY);
                            chessBoard[moveX][moveY] = 2;
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            step++;
                            addChessBoardXY(moveX,moveY);
                            emit start_emit(step,ChessEngine::evaluate(chessBoard,2),ChessEngine::evaluate(chessBoard,1));
                            score1.push_back(ChessEngine::evaluate(chessBoard,1));
                            score2.push_back(ChessEngine::evaluate(chessBoard,2));
                            if(isWin(moveX,moveY)== true){//满足胜利条件
                                whoWin = 2;//电脑获胜
                                qDebug("%d %d",gameMode,whoWin);
                                gameOver(gameMode,whoWin);
                            }
                            else if(step == 255){//平局
                                gameOver(gameMode,3);
                            }
                        }
                        preX = moveX;
                        preY = moveY;
                    }
                }
                else if(countWhoFirst == 1) {
                    if(countPlayer1Use == 1){//白子先手 白子玩家
                        chessBoard[moveX][moveY] = 1;
                        addChessBoardXY(moveX,moveY);
                        step++;
                        emit start_emit(step,ChessEngine::evaluate(chessBoard,2),ChessEngine::evaluate(chessBoard,1));
                        score1.push_back(ChessEngine::evaluate(chessBoard,1));
                        score2.push_back(ChessEngine::evaluate(chessBoard,2));
                        repaint();
                        if(isWin(moveX,moveY)== true){//满足胜利条件
                            whoWin = 1;//玩家获胜
                            qDebug("%d %d",gameMode,whoWin);
                            gameOver(gameMode,whoWin);

                        }
                        else if(step == 255){//平局
                            gameOver(gameMode,3);
                        }
                        if(gameState){
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            ChessEngine::nextStep(moveX,moveY);
                            chessBoard[moveX][moveY] = 2;
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            step++;
                            addChessBoardXY(moveX,moveY);
                            emit start_emit(step,ChessEngine::evaluate(chessBoard,2),ChessEngine::evaluate(chessBoard,1));
                            score1.push_back(ChessEngine::evaluate(chessBoard,1));
                            score2.push_back(ChessEngine::evaluate(chessBoard,2));
                            if(isWin(moveX,moveY)== true){//满足胜利条件
                                whoWin = 2;//电脑获胜
                                qDebug("%d %d",gameMode,whoWin);
                                gameOver(gameMode,whoWin);

                            }
                            else if(step == 255){//平局
                                gameOver(gameMode,3);
                            }
                        }
                        preX = moveX;
                        preY = moveY;
                    }
                    else if(countPlayer1Use == 0){//白子先手 黑子玩家
                        chessBoard[moveX][moveY] = 1;
                        addChessBoardXY(moveX,moveY);
                        step++;
                        emit start_emit(step,ChessEngine::evaluate(chessBoard,1),ChessEngine::evaluate(chessBoard,2));
                        score1.push_back(ChessEngine::evaluate(chessBoard,1));
                        score2.push_back(ChessEngine::evaluate(chessBoard,2));
                        repaint();
                        if(isWin(moveX,moveY)== true){//满足胜利条件
                            whoWin = 1;//玩家获胜
                            qDebug("%d %d",gameMode,whoWin);
                            gameOver(gameMode,whoWin);

                        }
                        else if(step == 255){//平局
                            gameOver(gameMode,3);
                        }
                        if(gameState){
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            ChessEngine::nextStep(moveX,moveY);
                            chessBoard[moveX][moveY] = 2;
                            qApp->processEvents(QEventLoop::ExcludeUserInputEvents);//它可以忽略用户的输入（鼠标和键盘事件）
                            step++;
                            addChessBoardXY(moveX,moveY);
                            emit start_emit(step,ChessEngine::evaluate(chessBoard,1),ChessEngine::evaluate(chessBoard,2));
                            score1.push_back(ChessEngine::evaluate(chessBoard,1));
                            score2.push_back(ChessEngine::evaluate(chessBoard,2));
                            if(isWin(moveX,moveY)== true){//满足胜利条件
                                whoWin = 2;//电脑获胜
                                qDebug("%d %d",gameMode,whoWin);
                                gameOver(gameMode,whoWin);
                            }
                            else if(step == 255){//平局
                                gameOver(gameMode,3);
                            }

                        }
                    }
                    preX = moveX;
                    preY = moveY;
                }

                update();
            }
        }


    }
}



int Chess::getChessBoard(int x,int y){
    return chessBoard[x][y];
}

void Chess::setChessBoard(int x,int y,int value){
    if(x >= 0 && x < 15 && y >= 0 && y < 15 && value<= 2 && value >= 0){
        chessBoard[x][y] = value;
    }
}

bool Chess:: deleteChessBoardXY(){
    if(chessBoardX.empty()  || chessBoardY.empty()){
        return false;
    }
    else{
        chessBoard[chessBoardX.back()][chessBoardY.back()] = 0;

        if(gameMode == 1){
            step--;
            emit start_emit(step,0,0);
        }
        else{
            if(step - 2 >= 0){
                step = step-2;
            }
            score1.pop_back();
            score2.pop_back();
            if(!score1.empty() && !score2.empty()){
                if(countPlayer1Use == 0){
                    emit start_emit(step,score1.back(),score2.back());
                }
                else if(countPlayer1Use == 1){
                    emit start_emit(step,score2.back(),score1.back());
                }
            }
        }

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
    score1.clear();
    score2.clear();
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
            DialogGameOver *dialogGameOver = new DialogGameOver(this);
            dialogGameOver->setLabelText(QString("玩家获胜！"));
            dialogGameOver->show();
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
            DialogGameOver *dialogGameOver = new DialogGameOver(this);
            dialogGameOver->setLabelText(QString("电脑获胜！"));
            dialogGameOver->show();
        }
    }
    else if(whoWin == 3){
        //平局
        DialogGameOver *dialogGameOver = new DialogGameOver();
        dialogGameOver->setLabelText(QString("平局！"));
    }
    gameState = false;
}




