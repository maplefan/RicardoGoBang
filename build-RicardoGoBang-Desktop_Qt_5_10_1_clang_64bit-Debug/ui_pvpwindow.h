/********************************************************************************
** Form generated from reading UI file 'pvpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVPWINDOW_H
#define UI_PVPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PVPWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_about;
    QPushButton *btn_giveup;
    QPushButton *btn_back;
    QPushButton *btn_undo;
    QPushButton *btn_start;
    QLabel *label_step;
    QLabel *label_rate;
    QWidget *widget_chess;

    void setupUi(QMainWindow *PVPWindow)
    {
        if (PVPWindow->objectName().isEmpty())
            PVPWindow->setObjectName(QStringLiteral("PVPWindow"));
        PVPWindow->resize(800, 610);
        PVPWindow->setMinimumSize(QSize(800, 610));
        PVPWindow->setMaximumSize(QSize(800, 610));
        centralwidget = new QWidget(PVPWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_about = new QPushButton(centralwidget);
        btn_about->setObjectName(QStringLiteral("btn_about"));
        btn_about->setGeometry(QRect(640, 540, 120, 50));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        btn_about->setFont(font);
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
        btn_giveup = new QPushButton(centralwidget);
        btn_giveup->setObjectName(QStringLiteral("btn_giveup"));
        btn_giveup->setGeometry(QRect(640, 420, 120, 50));
        btn_giveup->setFont(font);
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
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setGeometry(QRect(640, 480, 120, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font1.setPointSize(18);
        btn_back->setFont(font1);
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
        btn_undo->setFont(font);
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
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(640, 300, 120, 50));
        btn_start->setFont(font);
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
        label_step = new QLabel(centralwidget);
        label_step->setObjectName(QStringLiteral("label_step"));
        label_step->setGeometry(QRect(630, 20, 140, 50));
        label_step->setFont(font);
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
        widget_chess->setGeometry(QRect(0, 0, 600, 610));
        widget_chess->setMinimumSize(QSize(600, 610));
        widget_chess->setMaximumSize(QSize(600, 610));
        PVPWindow->setCentralWidget(centralwidget);

        retranslateUi(PVPWindow);

        QMetaObject::connectSlotsByName(PVPWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PVPWindow)
    {
        PVPWindow->setWindowTitle(QApplication::translate("PVPWindow", "RicardoGoBang", nullptr));
        btn_about->setText(QApplication::translate("PVPWindow", "\345\205\263\344\272\216", nullptr));
        btn_giveup->setText(QApplication::translate("PVPWindow", "\345\274\203\346\235\203", nullptr));
        btn_back->setText(QApplication::translate("PVPWindow", "\350\277\224\345\233\236", nullptr));
        btn_undo->setText(QApplication::translate("PVPWindow", "\346\202\224\346\243\213", nullptr));
        btn_start->setText(QApplication::translate("PVPWindow", "\345\274\200\345\247\213", nullptr));
        label_step->setText(QApplication::translate("PVPWindow", "STEP\357\274\232 0 \346\255\245", nullptr));
        label_rate->setText(QApplication::translate("PVPWindow", "\345\275\223\345\211\215\350\203\234\347\216\207\357\274\232\n"
"\347\231\275\357\274\232\351\273\221 = 50% \357\274\232 50%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PVPWindow: public Ui_PVPWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVPWINDOW_H
