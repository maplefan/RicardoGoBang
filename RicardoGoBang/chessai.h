#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
#include<utility>
#include<string.h>

#define BOARD_WIDTH 15

extern int isover;
extern int myturn;
extern int prex,prey;
extern int backnum,whitenum;

class ChessAI
{

public:
    void chess_isover(int x,int y,int turn);
    void chess_ai_killcount(int &x,int &y,bool &winFlag,int depth);
};

#endif // CHESS_H_INCLUDED
