#include "dialogabout.h"
#include "ui_dialogabout.h"

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    QLabel* labelSourceCode =new QLabel(this);
    labelSourceCode->setGeometry(111,170,300,21);
    labelSourceCode->setOpenExternalLinks(true);
    labelSourceCode->setText("<a href=\"https://github.com/maplefan/RicardoGoBang\">源代码");
    labelSourceCode->show();

    QLabel* labelMaplefan =new QLabel(this);
    labelMaplefan->setGeometry(111,240,300,21);

    labelMaplefan->setOpenExternalLinks(true);
    labelMaplefan->setText("<a href=\"https://maplefan.com\">maplefan.com");
    labelMaplefan->show();


    QLabel* labelGithub =new QLabel(this);
    labelGithub->setGeometry(111,260,300,21);
    labelGithub->setOpenExternalLinks(true);
    labelGithub->setText("<a href=\"https://github.com/maplefan\">github.com/maplefan");
    labelGithub->show();
}

DialogAbout::~DialogAbout()
{
    delete ui;
}
