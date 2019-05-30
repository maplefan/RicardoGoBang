#include "dialogchoosepiece.h"
#include "ui_dialogchoosepiece.h"
#include <QDebug>
#include <iostream>

extern int countWhoFirst;
extern int countPlayer1Use;
extern bool isFirstStep;
extern int chessBoard[15][15];
extern int gameMode;

DialogChoosePiece::DialogChoosePiece(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChoosePiece)
{
    ui->setupUi(this);
    groupButtonPlayer1Piece=new QButtonGroup(this);
        groupButtonPlayer1Piece->addButton(ui->radioButtonBlack,0);
        groupButtonPlayer1Piece->addButton(ui->radioButtonWhite,1);
        ui->radioButtonBlack->setChecked(true); //默认选中apple_radioButton

        groupButtonWhoFirst=new QButtonGroup(this);

        groupButtonWhoFirst->addButton(ui->radioButtonBlackFirst,0);
        groupButtonWhoFirst->addButton(ui->radioButtonWhiteFirst,1);
        ui->radioButtonBlackFirst->setChecked(true);

}

DialogChoosePiece::~DialogChoosePiece()
{
    delete ui;
}

bool DialogChoosePiece::getWhoFirst(){
    return whoFirst;
}

bool DialogChoosePiece::getPlayer1Use(){
    return player1Use;
}

void DialogChoosePiece::on_buttonBox_accepted()
{
    isFirstStep = true;
    int temp = groupButtonWhoFirst->checkedId();
    if(temp == 0){
        whoFirst = false;//黑子
    }
    else{
        whoFirst = true;//白子
    }
    temp = groupButtonPlayer1Piece->checkedId();
    if(temp == 0){
        player1Use = false;//黑子
    }
    else{
        player1Use = true;//白子
    }

    if(getWhoFirst() == false && getPlayer1Use() == false){
          countWhoFirst = 0;//黑色先手
          countPlayer1Use = 0;//玩家1为黑色
          isFirstStep = true;

    }
    else if(getWhoFirst() == false && getPlayer1Use() == true){
        countWhoFirst = 0;//黑色先手
        countPlayer1Use = 1;//玩家1为白色
        isFirstStep = true;
    }
    else if(getWhoFirst() == true && getPlayer1Use() == false){
        countWhoFirst = 1;//白色先手
        countPlayer1Use = 0;//玩家1为黑色
        isFirstStep = true;
    }
    else if(getWhoFirst() == true && getPlayer1Use() == true){
        countWhoFirst = 1;//白色先手
        countPlayer1Use = 1;//玩家1为白色
        isFirstStep = true;
    }
    restart_emit();
}
