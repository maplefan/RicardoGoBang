/********************************************************************************
** Form generated from reading UI file 'dialogabout.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGABOUT_H
#define UI_DIALOGABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogAbout
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *DialogAbout)
    {
        if (DialogAbout->objectName().isEmpty())
            DialogAbout->setObjectName(QStringLiteral("DialogAbout"));
        DialogAbout->resize(400, 300);
        label = new QLabel(DialogAbout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 71, 16));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:#1FB922"));
        label_2 = new QLabel(DialogAbout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 361, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft Sans Serif"));
        label_2->setFont(font1);
        label_3 = new QLabel(DialogAbout);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 150, 60, 16));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#1FB922"));
        label_4 = new QLabel(DialogAbout);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 170, 81, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(DialogAbout);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 200, 81, 16));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#1FB922"));
        label_6 = new QLabel(DialogAbout);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 10, 191, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_7 = new QLabel(DialogAbout);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 220, 111, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(DialogAbout);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 240, 71, 21));
        label_8->setFont(font1);
        label_9 = new QLabel(DialogAbout);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 260, 81, 21));
        label_9->setFont(font1);

        retranslateUi(DialogAbout);

        QMetaObject::connectSlotsByName(DialogAbout);
    } // setupUi

    void retranslateUi(QDialog *DialogAbout)
    {
        DialogAbout->setWindowTitle(QApplication::translate("DialogAbout", "\345\205\263\344\272\216", nullptr));
        label->setText(QApplication::translate("DialogAbout", "\350\277\231\346\230\257\344\273\200\344\271\210\357\274\232", nullptr));
        label_2->setText(QApplication::translate("DialogAbout", "\350\277\231\346\230\257\344\270\200\344\270\252\345\274\200\346\272\220\347\232\204\344\272\224\345\255\220\346\243\213\350\275\257\344\273\266\357\274\214\345\214\205\345\220\253\345\217\214\344\272\272\345\257\271\346\210\230\345\222\214\344\272\272\346\234\272\345\257\271\346\210\230\343\200\202\n"
"\347\224\261C++\345\217\212QT\346\241\206\346\236\266\345\256\214\346\210\220\357\274\214\346\227\240\345\220\216\345\217\260\351\200\232\344\277\241\357\274\214AI\345\205\267\346\234\211\344\270\200\345\256\232\347\232\204\346\243\213\345\212\233\343\200\202\n"
"\350\257\245\350\275\257\344\273\266\350\267\250Windows\357\274\214MacOS\357\274\214Linux\344\270\211\345\244\247\344\270\273\346\265\201\346\241\214\351\235\242\346\223\215\344\275\234\347\263\273\347\273\237\343\200\202", nullptr));
        label_3->setText(QApplication::translate("DialogAbout", "\346\272\220\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("DialogAbout", "\346\272\220\347\240\201\345\234\250\350\277\231\351\207\214\357\274\232", nullptr));
        label_5->setText(QApplication::translate("DialogAbout", "\345\205\263\344\272\216\344\275\234\350\200\205\357\274\232", nullptr));
        label_6->setText(QApplication::translate("DialogAbout", "RicardoGoBang", nullptr));
        label_7->setText(QApplication::translate("DialogAbout", "\344\275\234\350\200\205@o\351\243\216\345\220\221\346\231\232o", nullptr));
        label_8->setText(QApplication::translate("DialogAbout", "\344\270\252\344\272\272\347\275\221\347\253\231\357\274\232", nullptr));
        label_9->setText(QApplication::translate("DialogAbout", "github\344\270\273\351\241\265\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAbout: public Ui_DialogAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGABOUT_H
