#ifndef UI_DIFF_H
#define UI_DIFF_H

#include <QtCore/QVariant>
#include <qdebug.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>

QT_BEGIN_NAMESPACE

class Ui_Dialog : public QDialog
{
    Q_OBJECT

public:
    QPushButton* level_3;
    QPushButton* level_1;
    QPushButton* level_4;
    QPushButton* level_2;

    Ui_Dialog(QWidget* parent = nullptr) : QDialog(parent)
    {
        setupUi(this);
    }

    void setupUi(QDialog* Dialog)
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
        QObject::connect(level_1, &QPushButton::clicked, this, &Ui_Dialog::lev_1);
        QObject::connect(level_2, &QPushButton::clicked, this, &Ui_Dialog::lev_2);
        QObject::connect(level_3, &QPushButton::clicked, this, &Ui_Dialog::lev_3);
        QObject::connect(level_4, &QPushButton::clicked, this, &Ui_Dialog::lev_4);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog* Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        level_3->setText(QCoreApplication::translate("Dialog", "\351\253\230\347\272\247", nullptr));
        level_1->setText(QCoreApplication::translate("Dialog", "\345\210\235\347\272\247", nullptr));
        level_4->setText(QCoreApplication::translate("Dialog", "\345\234\260\347\213\261", nullptr));
        level_2->setText(QCoreApplication::translate("Dialog", "\344\270\255\347\272\247", nullptr));
    } // retranslateUi

signals:
    void level1Clicked();
    void level2Clicked();
    void level3Clicked();
    void level4Clicked();
    void handleCloseEvent();

private slots:
    void lev_1() { emit level1Clicked(); close(); }
    void lev_2() { emit level2Clicked(); close(); }
    void lev_3() { emit level3Clicked(); close(); }
    void lev_4() { emit level4Clicked(); close(); }

protected:
    void closeEvent(QCloseEvent* event) override {
        emit handleCloseEvent();
        qDebug() << "close";
    }
}; 



namespace Ui {
    class Dialog : public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFF_H
