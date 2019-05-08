/********************************************************************************
** Form generated from reading UI file 'dialoggameover.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGAMEOVER_H
#define UI_DIALOGGAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogGameOver
{
public:
    QLabel *label_gameover;

    void setupUi(QDialog *DialogGameOver)
    {
        if (DialogGameOver->objectName().isEmpty())
            DialogGameOver->setObjectName(QStringLiteral("DialogGameOver"));
        DialogGameOver->resize(200, 150);
        label_gameover = new QLabel(DialogGameOver);
        label_gameover->setObjectName(QStringLiteral("label_gameover"));
        label_gameover->setGeometry(QRect(0, 0, 200, 150));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft Sans Serif"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label_gameover->setFont(font);
        label_gameover->setStyleSheet(QStringLiteral("color:#1FB922"));
        label_gameover->setAlignment(Qt::AlignCenter);

        retranslateUi(DialogGameOver);

        QMetaObject::connectSlotsByName(DialogGameOver);
    } // setupUi

    void retranslateUi(QDialog *DialogGameOver)
    {
        DialogGameOver->setWindowTitle(QApplication::translate("DialogGameOver", "GameOver\357\274\201", nullptr));
        label_gameover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogGameOver: public Ui_DialogGameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGAMEOVER_H
