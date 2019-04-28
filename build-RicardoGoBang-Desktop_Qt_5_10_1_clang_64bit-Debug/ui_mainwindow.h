/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnPVP;
    QPushButton *btnPVM;
    QPushButton *btnQuit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 610);
        MainWindow->setMinimumSize(QSize(800, 610));
        MainWindow->setMaximumSize(QSize(800, 610));
        MainWindow->setBaseSize(QSize(800, 600));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnPVP = new QPushButton(centralWidget);
        btnPVP->setObjectName(QStringLiteral("btnPVP"));
        btnPVP->setGeometry(QRect(300, 150, 200, 70));
        btnPVP->setBaseSize(QSize(200, 70));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        btnPVP->setFont(font);
        btnPVP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnPVM = new QPushButton(centralWidget);
        btnPVM->setObjectName(QStringLiteral("btnPVM"));
        btnPVM->setGeometry(QRect(300, 250, 200, 70));
        btnPVM->setBaseSize(QSize(200, 70));
        btnPVM->setFont(font);
        btnPVM->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnQuit = new QPushButton(centralWidget);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setGeometry(QRect(300, 350, 200, 70));
        btnQuit->setBaseSize(QSize(200, 70));
        btnQuit->setFont(font);
        btnQuit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RicardoGoBang", nullptr));
        btnPVP->setText(QApplication::translate("MainWindow", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        btnPVM->setText(QApplication::translate("MainWindow", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        btnQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
