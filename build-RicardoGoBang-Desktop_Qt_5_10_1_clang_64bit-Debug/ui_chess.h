/********************************************************************************
** Form generated from reading UI file 'chess.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESS_H
#define UI_CHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chess
{
public:

    void setupUi(QWidget *Chess)
    {
        if (Chess->objectName().isEmpty())
            Chess->setObjectName(QStringLiteral("Chess"));
        Chess->resize(600, 600);

        retranslateUi(Chess);

        QMetaObject::connectSlotsByName(Chess);
    } // setupUi

    void retranslateUi(QWidget *Chess)
    {
        Chess->setWindowTitle(QApplication::translate("Chess", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chess: public Ui_Chess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESS_H
