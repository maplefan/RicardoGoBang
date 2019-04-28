/********************************************************************************
** Form generated from reading UI file 'pvmwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVMWINDOW_H
#define UI_PVMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PVMWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_back;
    QPushButton *btn_undo;
    QPushButton *btn_giveup;
    QPushButton *btn_start;
    QPushButton *btn_about;
    QLabel *label_step;
    QLabel *label_rate;
    QWidget *widget_chess;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *PVMWindow)
    {
        if (PVMWindow->objectName().isEmpty())
            PVMWindow->setObjectName(QStringLiteral("PVMWindow"));
        PVMWindow->resize(800, 610);
        PVMWindow->setMinimumSize(QSize(800, 610));
        PVMWindow->setMaximumSize(QSize(800, 610));
        centralwidget = new QWidget(PVMWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(640, 480, 120, 50));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(18);
        btn_back->setFont(font);
        btn_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 20px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #00A1F1, stop: 1 #0072C6);\n"
"     }\n"
" \n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
" QPushButton:default {\n"
"         border-color: navy; /* \344\275\277\345\276\227\346\214\211\351\222\256\346\230\276\347\244\272\345\217\230\345\276\227\346\233\264\345\212\240\347\252\201\345\207\272 */\n"
"     }\n"
""));
        btn_undo = new QPushButton(centralwidget);
        btn_undo->setObjectName(QStringLiteral("btn_undo"));
        btn_undo->setGeometry(QRect(640, 360, 120, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        btn_undo->setFont(font1);
        btn_undo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 20px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #00A1F1, stop: 1 #0072C6);\n"
"     }\n"
" \n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
" QPushButton:default {\n"
"         border-color: navy; /* \344\275\277\345\276\227\346\214\211\351\222\256\346\230\276\347\244\272\345\217\230\345\276\227\346\233\264\345\212\240\347\252\201\345\207\272 */\n"
"     }\n"
""));
        btn_giveup = new QPushButton(centralwidget);
        btn_giveup->setObjectName(QStringLiteral("btn_giveup"));
        btn_giveup->setGeometry(QRect(640, 420, 120, 50));
        btn_giveup->setFont(font1);
        btn_giveup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 20px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #00A1F1, stop: 1 #0072C6);\n"
"     }\n"
" \n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
" QPushButton:default {\n"
"         border-color: navy; /* \344\275\277\345\276\227\346\214\211\351\222\256\346\230\276\347\244\272\345\217\230\345\276\227\346\233\264\345\212\240\347\252\201\345\207\272 */\n"
"     }\n"
""));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(640, 300, 120, 50));
        btn_start->setFont(font1);
        btn_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 20px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #00A1F1, stop: 1 #0072C6);\n"
"     }\n"
" \n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
" QPushButton:default {\n"
"         border-color: navy; /* \344\275\277\345\276\227\346\214\211\351\222\256\346\230\276\347\244\272\345\217\230\345\276\227\346\233\264\345\212\240\347\252\201\345\207\272 */\n"
"     }\n"
""));
        btn_about = new QPushButton(centralwidget);
        btn_about->setObjectName(QStringLiteral("btn_about"));
        btn_about->setGeometry(QRect(640, 540, 120, 50));
        btn_about->setFont(font1);
        btn_about->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"         border: 2px solid #8f8f91;\n"
"         border-radius: 20px;\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #00A1F1, stop: 1 #0072C6);\n"
"     }\n"
" \n"
"     QPushButton:pressed {\n"
"         background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                           stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"     }\n"
" QPushButton:default {\n"
"         border-color: navy; /* \344\275\277\345\276\227\346\214\211\351\222\256\346\230\276\347\244\272\345\217\230\345\276\227\346\233\264\345\212\240\347\252\201\345\207\272 */\n"
"     }\n"
""));
        label_step = new QLabel(centralwidget);
        label_step->setObjectName(QStringLiteral("label_step"));
        label_step->setGeometry(QRect(630, 20, 140, 50));
        label_step->setFont(font1);
        label_step->setStyleSheet(QStringLiteral("color:#f65314"));
        label_rate = new QLabel(centralwidget);
        label_rate->setObjectName(QStringLiteral("label_rate"));
        label_rate->setGeometry(QRect(630, 80, 140, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_rate->setFont(font2);
        label_rate->setStyleSheet(QStringLiteral("color:#f65314"));
        widget_chess = new QWidget(centralwidget);
        widget_chess->setObjectName(QStringLiteral("widget_chess"));
        widget_chess->setGeometry(QRect(0, 0, 600, 600));
        verticalLayout = new QVBoxLayout(widget_chess);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        PVMWindow->setCentralWidget(centralwidget);

        retranslateUi(PVMWindow);

        QMetaObject::connectSlotsByName(PVMWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PVMWindow)
    {
        PVMWindow->setWindowTitle(QApplication::translate("PVMWindow", "RicardoGoBang", nullptr));
        btn_back->setText(QApplication::translate("PVMWindow", "\350\277\224\345\233\236", nullptr));
        btn_undo->setText(QApplication::translate("PVMWindow", "\346\202\224\346\243\213", nullptr));
        btn_giveup->setText(QApplication::translate("PVMWindow", "\345\274\203\346\235\203", nullptr));
        btn_start->setText(QApplication::translate("PVMWindow", "\345\274\200\345\247\213", nullptr));
        btn_about->setText(QApplication::translate("PVMWindow", "\345\205\263\344\272\216", nullptr));
        label_step->setText(QApplication::translate("PVMWindow", "STEP\357\274\232 0 \346\255\245", nullptr));
        label_rate->setText(QApplication::translate("PVMWindow", "\345\275\223\345\211\215\350\203\234\347\216\207\357\274\232\n"
"\347\231\275\357\274\232\351\273\221 = 50% \357\274\232 50%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PVMWindow: public Ui_PVMWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVMWINDOW_H
