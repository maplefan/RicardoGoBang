#include "chess.h"
#include "ui_chess.h"

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess)
{
    ui->setupUi(this);
}

Chess::~Chess()
{
    delete ui;
}

void Chess::paintEvent(QPaintEvent *)
{
    QPainter *paint=new QPainter;



    paint->begin(this);//开始绘制
        paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
   paint->fillRect(QRect(10,10,590,590), QBrush(QColor(215,156,80)));



    for(int i = 0;i<15;i++){
        paint->drawLine(25+40*i,25,25+40*i,585);
    }
    for(int i = 0;i<15 ;i++){
        paint->drawLine(25,25+40*i,585,25+40*i);
    }




    paint->end();//结束绘制

}
