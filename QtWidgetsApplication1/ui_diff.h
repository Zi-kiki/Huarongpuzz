/********************************************************************************
** Form generated from reading UI file 'diff.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFF_H
#define UI_DIFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *level_3;
    QPushButton *level_1;
    QPushButton *level_4;
    QPushButton *level_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(258, 331);
        level_3 = new QPushButton(Dialog);
        level_3->setObjectName(QString::fromUtf8("level_3"));
        level_3->setGeometry(QRect(50, 170, 161, 51));
        QFont font;
        font.setPointSize(20);
        level_3->setFont(font);
        level_1 = new QPushButton(Dialog);
        level_1->setObjectName(QString::fromUtf8("level_1"));
        level_1->setGeometry(QRect(50, 30, 161, 51));
        level_1->setFont(font);
        level_4 = new QPushButton(Dialog);
        level_4->setObjectName(QString::fromUtf8("level_4"));
        level_4->setGeometry(QRect(50, 240, 161, 51));
        level_4->setFont(font);
        level_2 = new QPushButton(Dialog);
        level_2->setObjectName(QString::fromUtf8("level_2"));
        level_2->setGeometry(QRect(50, 100, 161, 51));
        level_2->setFont(font);

        retranslateUi(Dialog);
        QObject::connect(level_1, SIGNAL(clicked()), Dialog, SLOT(lev_1()));
        QObject::connect(level_2, SIGNAL(clicked()), Dialog, SLOT(lev_2()));
        QObject::connect(level_3, SIGNAL(clicked()), Dialog, SLOT(lev_3()));
        QObject::connect(level_4, SIGNAL(clicked()), Dialog, SLOT(lev_4()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        level_3->setText(QCoreApplication::translate("Dialog", "\351\253\230\347\272\247", nullptr));
        level_1->setText(QCoreApplication::translate("Dialog", "\345\210\235\347\272\247", nullptr));
        level_4->setText(QCoreApplication::translate("Dialog", "\345\234\260\347\213\261", nullptr));
        level_2->setText(QCoreApplication::translate("Dialog", "\344\270\255\347\272\247", nullptr));
    } // retranslateUi
private slots:
    void lev_1();
};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFF_H


void lev_1() {

}