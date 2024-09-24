#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "diff.h"
#include <QFileDialog>
#include <algorithm>
#include <random>
#include <iterator>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class ui;
    QPushButton* buttons[16];
    Ui::Dialog diff;
    QDialog* diffDialog = nullptr;
    void resetArray();
    int levell = 0;
    int levelr = 0;
    void setWidgetsEnabled(QWidget* parent, bool enabled);

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
    void gen();
    void update();
    void openfile();
    void BtnClicked(int index);
    void shuffleArray(int arr[], int n);
    void reverseArray();
    void openDiffWindow();
    void handleLevel1();
    void handleLevel2();
    void handleLevel3();
    void handleLevel4();
    void handleCloseEvent();
    void solve();
    void save();
    int rand(int a, int b, int c);
    int change(int c, int i);
    int judgment();
};
