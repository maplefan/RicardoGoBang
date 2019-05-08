/********************************************************************************
** Form generated from reading UI file 'dialogchoosepiece.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHOOSEPIECE_H
#define UI_DIALOGCHOOSEPIECE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogChoosePiece
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *radioButtonBlack;
    QRadioButton *radioButtonWhite;
    QRadioButton *radioButtonBlackFirst;
    QRadioButton *radioButtonWhiteFirst;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *DialogChoosePiece)
    {
        if (DialogChoosePiece->objectName().isEmpty())
            DialogChoosePiece->setObjectName(QStringLiteral("DialogChoosePiece"));
        DialogChoosePiece->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogChoosePiece);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        radioButtonBlack = new QRadioButton(DialogChoosePiece);
        radioButtonBlack->setObjectName(QStringLiteral("radioButtonBlack"));
        radioButtonBlack->setGeometry(QRect(50, 50, 151, 61));
        radioButtonWhite = new QRadioButton(DialogChoosePiece);
        radioButtonWhite->setObjectName(QStringLiteral("radioButtonWhite"));
        radioButtonWhite->setGeometry(QRect(210, 50, 151, 61));
        radioButtonBlackFirst = new QRadioButton(DialogChoosePiece);
        radioButtonBlackFirst->setObjectName(QStringLiteral("radioButtonBlackFirst"));
        radioButtonBlackFirst->setGeometry(QRect(50, 130, 151, 61));
        radioButtonWhiteFirst = new QRadioButton(DialogChoosePiece);
        radioButtonWhiteFirst->setObjectName(QStringLiteral("radioButtonWhiteFirst"));
        radioButtonWhiteFirst->setGeometry(QRect(210, 130, 151, 61));
        label = new QLabel(DialogChoosePiece);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 191, 16));
        label_2 = new QLabel(DialogChoosePiece);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 120, 171, 16));

        retranslateUi(DialogChoosePiece);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogChoosePiece, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogChoosePiece, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogChoosePiece);
    } // setupUi

    void retranslateUi(QDialog *DialogChoosePiece)
    {
        DialogChoosePiece->setWindowTitle(QApplication::translate("DialogChoosePiece", "Dialog", nullptr));
        radioButtonBlack->setText(QApplication::translate("DialogChoosePiece", "\351\273\221\345\255\220", nullptr));
        radioButtonWhite->setText(QApplication::translate("DialogChoosePiece", "\347\231\275\345\255\220", nullptr));
        radioButtonBlackFirst->setText(QApplication::translate("DialogChoosePiece", "\351\273\221\345\255\220\345\205\210\346\211\213", nullptr));
        radioButtonWhiteFirst->setText(QApplication::translate("DialogChoosePiece", "\347\231\275\345\255\220\345\205\210\346\211\213", nullptr));
        label->setText(QApplication::translate("DialogChoosePiece", "\351\200\211\346\213\251\347\216\251\345\256\2661\346\243\213\345\255\220", nullptr));
        label_2->setText(QApplication::translate("DialogChoosePiece", "\351\200\211\346\213\251\345\205\210\346\211\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChoosePiece: public Ui_DialogChoosePiece {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHOOSEPIECE_H
