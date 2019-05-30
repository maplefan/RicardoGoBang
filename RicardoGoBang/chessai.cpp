
#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
#include<utility>
#include<string.h>
#include<chessai.h>
using namespace std;
extern int chessBoard[BOARD_WIDTH][BOARD_WIDTH];


void ChessAI::chess_isover(int x,int y,int turn)
{
    int num=1;
    int i,j;
    for(i=y-1;i>=0;--i)
        if(chessBoard[x][i]==turn)	++num;
        else	break;
    for(i=y+1;i<16;++i)
        if(chessBoard[x][i]==turn)	++num;
        else	break;
    if(num>=5)
    {
        isover=turn;
        return;
    }
    num=1;
    for(i=x-1;i>=0;--i)
        if(chessBoard[i][y]==turn)	++num;
        else	break;
    for(i=x+1;i<16;++i)
        if(chessBoard[i][y]==turn)	++num;
        else	break;
    if(num>=5)
    {
        isover=turn;
        return;
    }
    num=1;
    for(i=x-1,j=y-1;i>=0&&j>=0;--i,--j)
        if(chessBoard[i][j]==turn)	++num;
        else	break;
    for(i=x+1,j=y+1;i<16&&j<16;++i,++j)
        if(chessBoard[i][j]==turn)	++num;
        else	break;
    if(num>=5)
    {
        isover=turn;
        return;
    }
    num=1;
    for(i=x-1,j=y+1;i>=0&&j<16;--i,++j)
        if(chessBoard[i][j]==turn)	++num;
        else	break;
    for(i=x+1,j=y-1;i<16&&j>=0;++i,--j)
        if(chessBoard[i][j]==turn)	++num;
        else	break;
    if(num>=5)
    {
        isover=turn;
        return;
    }
    if(backnum+whitenum==16*16)
    {
        isover=3;
        return;
    }
}
static int score[17][17];

void generatepoint(vector< pair<int,int> > &v);
int scoretable(int number,int empty1);
int countscore(vector<int> n,int turn);
bool hasne(int x,int y);
bool hasne(int x,int y)//判断该处是否可下
{
    int i,j;
    for(i=(x-1>0?x-1:0);i<=x+1&&i<16;++i)
        for(j=(y-1>0?y-1:0);j<=y+1&&j<16;++j)
            if(i!=0||j!=0)
                if(chessBoard[i][j]!=0)
                    return true;
    return false;
}
int evaluate_point(int x,int y,int turn)
{
    int scoree=0;
    int number=0;
    int empty1=0;
    int i,j;
    for(i=y-1;i>=0&&i>y-6;--i)
        if(chessBoard[x][i]==turn)	++number;
        else if(chessBoard[x][i]==0)	{++empty1;break;}
        else break;
    for(i=y+1;i<16&&i<y+6;++i)
        if(chessBoard[x][i]==turn)	++number;
        else if(chessBoard[x][i]==0)	{++empty1;break;}
        else break;
    scoree+=scoretable(number+1,empty1);
    number=0;
    empty1=0;
    for(i=x-1;i>=0&&i>x-6;--i)
        if(chessBoard[i][y]==turn)	++number;
        else if(chessBoard[i][y]==0)	{++empty1;break;}
        else break;
    for(i=x+1;i<16&&i<x+6;++i)
        if(chessBoard[i][y]==turn)	++number;
        else if(chessBoard[i][y]==0)	{++empty1;break;}
        else break;
    scoree+=scoretable(number+1,empty1);
    number=0;
    empty1=0;
    for(i=x-1,j=y-1;i>=0&&j>=0&&i>x-6&&j>y-6;--i,--j)
        if(chessBoard[i][j]==turn)	++number;
        else if(chessBoard[i][j]==0)	{++empty1;break;}
        else	break;
    for(i=x+1,j=y+1;i<16&&j<16&&i<x+6&&j<y+6;++i,++j)
        if(chessBoard[i][j]==turn)	++number;
        else if(chessBoard[i][j]==0)	{++empty1;break;}
        else	break;
    scoree+=scoretable(number+1,empty1);
    number=0;
    empty1=0;
    for(i=x-1,j=y+1;i>=0&&i>x-6&&j<16&&j<y+6;--i,++j)
        if(chessBoard[i][j]==turn)	++number;
        else if(chessBoard[i][j]==0)	{++empty1;break;}
        else	break;
    for(i=x+1,j=y-1;i<16&&i<x+6&&j>=0&&j>y-6;++i,--j)
        if(chessBoard[i][j]==turn)	++number;
        else if(chessBoard[i][j]==0)	{++empty1;break;}
        else	break;
    scoree+=scoretable(number+1,empty1);
    return scoree;
}

void generatepoint(vector< pair<int,int> > &v)
{
    vector<	pair<int,int> > humfive;
    vector< pair<int,int> > comfour;
    vector< pair<int,int> > humfour;
    vector< pair<int,int> >	comdoublethree;
    vector< pair<int,int> >	humdoublethree;
    vector< pair<int,int> > comthree;
    vector< pair<int,int> > humthree;
    vector<	pair<int,int> > comtwo;
    vector< pair<int,int> > humtwo;
    vector< pair<int,int> > others;
    for(int i=0;i<16;++i)
        for(int j=0;j<16;++j)
            if(chessBoard[i][j]==0&&hasne(i,j))
            {
                int scorecom=evaluate_point(i,j,2);
                int scorehum=evaluate_point(i,j,1);
                pair<int,int> p;
                p.first=i;
                p.second=j;
                if(scorecom>=100000)	{v.push_back(p);return;}
                else if(scorehum>=100000)	{humfive.push_back(p);}
                else if(scorecom>=10000)	comfour.push_back(p);
                else if(scorehum>=10000)	humfour.push_back(p);
                else if(scorecom>=2*1000) 	comdoublethree.push_back(p);
                else if(scorehum>=2*1000)	humdoublethree.push_back(p);
                else if(scorecom>=1000)	comthree.push_back(p);
                else if(scorehum>=1000)	humthree.push_back(p);
                else if(scorecom>=100)	comtwo.push_back(p);
                else if(scorehum>=100)	humtwo.push_back(p);
                else 	 others.push_back(p);
            }
    if(humfive.size()>0)	{v=humfive;return;}
    if(comfour.size()>0||humfour.size()>0)	{v=comfour;v.insert(v.end(),humfour.begin(),humfour.end());return;}
    if(comdoublethree.size()>0||humdoublethree.size()>0)	{v=comdoublethree;v.insert(v.end(),humdoublethree.begin(),humdoublethree.end());return;}
    v=comthree;
    v.insert(v.end(),humthree.begin(),humthree.end());
    v.insert(v.end(),comtwo.begin(),comtwo.end());
    v.insert(v.end(),humtwo.begin(),humtwo.end());
    v.insert(v.end(),others.begin(),others.end());
    return;
}

int scoretable(int number,int empty1)
{
    if(number>=5)	return 100000;
    else if(number==4)
    {
        if(empty1==2)	return 10000;
        else if(empty1==1)	return 1000;
    }
    else if(number==3)
    {
        if(empty1==2)	return 1000;
        else if(empty1==1)	return 100;
    }
    else if(number==2)
    {
        if(empty1==2)	return 100;
        else if(empty1==1)	return 10;
    }
    else if(number==1&&empty1==2)	return 10;
    return 0;
}

struct Node
{
    int x;
    int y;
    int s;
    Node(int i,int j,int k):x(i),y(j),s(k){}
};
vector<Node> min_kill(int turn,int depth,int x,int y,bool &tmp ,bool &flagWin);
vector<Node> max_kill(int turn,int depth,int x,int y,bool &tmp , bool &flagWin);
void generatepoint_2(int turn,int scoree,vector<Node> &v);
bool cmp(Node a,Node b)
{
    return a.s>b.s;
}

void generatepoint_2(int turn,int scoree,vector<Node> &v)
{
    for(int i=0;i<16;++i)
        for(int j=0;j<16;++j)
            if(chessBoard[i][j]==0&&hasne(i,j))
                if(turn==0)//轮到玩家落子，玩家需要找到黑子最有利的空子+白子最有危险的空子，然后攻守随玩家
                {
                    int comscore=evaluate_point(i,j,2);
                    int humscore=evaluate_point(i,j,1);
                    if(comscore+humscore>scoree)
                    {
                        Node p(i,j,comscore+humscore);
                        v.push_back(p);
                    }
                }
                else//轮到电脑落子，电脑只管找杀招
                {
                    int s=evaluate_point(i,j,turn);
                    if(s>scoree)
                    {
                        Node p(i,j,s);
                        v.push_back(p);
                    }
                }
    sort(v.begin(),v.end(),cmp);//空子按优先级排序
}

vector<Node> min_kill(int turn,int depth,int x,int y,bool &tmp,bool &winFlag)
{
    cout<<depth<<endl;
    vector<Node> v;
    ChessAI cc;
    cc.chess_isover(x,y,2);	//上一步是机器落子，落子的地方才有可能产生输赢
    if(isover==2)			//电脑赢了
    {
        winFlag = true;
        isover=0;
        tmp=true;
        return v;
    }
    if(depth<0)				//depth步内，玩家守的住了
    {
        tmp=false;
        return v;
    }
    vector<Node> p;
    generatepoint_2(0,1000,p);//找出所有大于活三的空子。玩家防守的话，可以是占电脑连成活四的空子，也可以是自己出击先成死四什么的。所以传的是0
    int len=p.size();
    if(len==0)				//如果没有这样的空子，表示玩家到这一步就守住了
    {
        tmp=false;
        return v;
    }
    vector< vector<Node> > cands;
    for(int i=0;i<len;++i)	//如果有这样的空子
    {
        bool tmp=false;
        chessBoard[p[i].x][p[i].y]=(turn==1)?2:1;
        v.clear();
        v=max_kill(turn,depth-1,p[i].x,p[i].y,tmp,winFlag);
        chessBoard[p[i].x][p[i].y]=0;
        if(tmp)//这个空子占了，后推几步还是得输
        {
            vector<Node> kk;
            kk.push_back(p[i]);
            v.insert(v.begin(),kk.begin(),kk.end());
            cands.push_back(v);
            continue;//继续找可以防守住的空子
        }
        else
        {
            tmp=false;
            return v;//这个空子可以防守住，那就直接返回
        }
    }
    int i=rand()%cands.size();
    return cands[i];//所有空子挨个占，depth内没一个能防住的，随机抽一个
}

vector<Node> max_kill(int turn,int depth,int x,int y,bool &tmp,bool &winFlag)
{
    cout<<depth<<endl;
    vector<Node> v;
    ChessAI cc;
    cc.chess_isover(x,y,1);//上一步是玩家落子，落子的地方才有可能产生输赢
    if(isover==1)//玩家不仅守住了，还赢了
    {
        isover=0;
        tmp=false;
        return v;
    }
    if(depth<0)//玩家守住了
    {
        winFlag = false;
        tmp=false;
        return v;
    }
    vector<Node> p;
    generatepoint_2(0,2000,p);//产生所有杀招空子队列
    if(p.size()==0)//没有这样的空子，玩家守住了
    {
        tmp=false;
        return v;
    }
    int len=p.size();
    for(int i=0;i<len;++i)
    {
        bool tmp=false;
        chessBoard[p[i].x][p[i].y]=turn;
        v.clear();
        v=min_kill(turn,depth-1,p[i].x,p[i].y,tmp,winFlag);
        chessBoard[p[i].x][p[i].y]=0;
        if(tmp)
        {
            vector<Node> kk;
            kk.push_back(p[i]);
            v.insert(v.begin(),kk.begin(),kk.end());
            return v;
        }
    }
    tmp=false;
    return v;
}

void ChessAI::chess_ai_killcount(int &x,int &y,bool &winFlag,int depth)
{
    vector< pair<int,int> > v;
    generatepoint(v);
    int len=v.size();
    vector< pair<int,int> > v2;
    for(int i=0;i<len;++i)
    {
        chessBoard[v[i].first][v[i].second]=2;
        bool tmp=false;
        min_kill(2,depth,v[i].first,v[i].second,tmp,winFlag);
        if(tmp){
            v2.push_back(v[i]);
        }
        chessBoard[v[i].first][v[i].second]=0;
    }
    len=v2.size();
    cout<<len<<endl;
    if(len==0)//若无杀招，或者杀招都不能在depth内奏效，则取优先级最高的空子
    {
        x=v[0].first;
        y=v[0].second;
        return;
    }

    int i=(int)(rand()%len);
x=v2[i].first;
    y=v2[i].second;
}
