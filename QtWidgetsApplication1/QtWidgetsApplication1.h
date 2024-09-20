#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <QFileDialog>

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class ui;
    QPushButton* buttons[16];

private slots:
    void _1Clicked();
    void _2Clicked();
    void _3Clicked();
    void _4Clicked();
    void _5Clicked();
    void _6Clicked();
    void _7Clicked();
    void _8Clicked();
    void _9Clicked();
    void _10Clicked();
    void _11Clicked();
    void _12Clicked();
    void _13Clicked();
    void _14Clicked();
    void _15Clicked();
    void _16Clicked();
    void openfile();
    void gen();
    void update();
    void BtnClicked(int index);
    void shuffleArray(int arr[], int n);
    void openDiffWindow();
    int judgment();
};
