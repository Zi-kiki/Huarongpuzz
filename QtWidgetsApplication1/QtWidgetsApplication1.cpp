#include "QtWidgetsApplication1.h"
#include "diff.h"
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <qdebug.h>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>


using namespace std;


const int N = 4;
extern const QString none = "";
extern const int target[N * N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
extern int hrl[N * N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };

//$(Qt_RUNTIME_)

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint);
    buttons[0] = ui._1;
    buttons[1] = ui._2;
    buttons[2] = ui._3;
    buttons[3] = ui._4;
    buttons[4] = ui._5;
    buttons[5] = ui._6;
    buttons[6] = ui._7;
    buttons[7] = ui._8;
    buttons[8] = ui._9;
    buttons[9] = ui._10;
    buttons[10] = ui._11;
    buttons[11] = ui._12;
    buttons[12] = ui._13;
    buttons[13] = ui._14;
    buttons[14] = ui._15;
    buttons[15] = ui._16;

    connect(ui.openfile, &QAction::triggered, this, &QtWidgetsApplication1::openfile);
    connect(ui.gen, &QAction::triggered, this, &QtWidgetsApplication1::gen);
    connect(ui.save, &QAction::triggered, this, &QtWidgetsApplication1::save);
    connect(ui.solve, &QAction::triggered, this, &QtWidgetsApplication1::solve);
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::BtnClicked(int index) {

    int directions[4] = { -1, 1, -4, 4 };

    if (judgment() != 0) {
        for (int i = 0; i < 4; ++i) {
            int newIndex = index + directions[i];
            if (newIndex >= 0 && newIndex < 16 && hrl[newIndex] == 0) {
                hrl[newIndex] = hrl[index];
                hrl[index] = 0;
                break;
            }
        }
        update();
    }
}

void QtWidgetsApplication1::openfile() {
    QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("选择文件"), "", QStringLiteral("所有文件 (*.*);;图像文件 (*.png *.jpg)"));
    if (!fileName.isEmpty()) {
        qDebug() << "选择的文件:" << fileName;
    }
}


void QtWidgetsApplication1::gen() {
    int dg = 0;
    int cc;
    int bb;
    resetArray();
    openDiffWindow();
    if (levell == 100) {
        cc = bb = rand(1, 2, 3);
        rand(1, 15 - cc, 1);
        change(cc, bb);
        dg = judgment();
        if (dg < 100) {
            reverseArray();
        }
    }
    else {
        shuffleArray(hrl, 15);
        while (1) {
            dg = judgment();
            if (dg % 2 != 0 || dg < levell || dg > levelr) {
                shuffleArray(hrl, 15);
            }
            else {
                break;
            }
        }
    }

    update();
}

void QtWidgetsApplication1::update() {
    for (int i = 0; i < 16; ++i) {
        if (hrl[i] == 0) {
            buttons[i]->setEnabled(false);
            buttons[i]->setText(none);
        }
        else {
            buttons[i]->setEnabled(true);
            buttons[i]->setText(QString::number(hrl[i]));
        }
    }
    if (judgment() == 0) {
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("你赢了！"), QMessageBox::Ok);
    }
}

int QtWidgetsApplication1::judgment() {
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1; j < 16; j++) {
            if (hrl[i] > hrl[j] && hrl[j] != 0) {
                sum++;
            }
        }
    }
    return sum;
}

int QtWidgetsApplication1::change(int c, int i) {
    int temp = 0;

    for (; c > 0; c--) {
        temp = hrl[i];
        hrl[i] = hrl[i + c];
        hrl[i + c] = temp;
    }

    return 0;
}

int QtWidgetsApplication1::rand(int a, int b, int c) {
    int random_number;
    unsigned seed = static_cast<unsigned>(time(0));
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(a, b);

    if (c == 3) {
        random_number = distribution(generator) * 2 - 1;
    }
    else {
        random_number = distribution(generator) * c;
    }
    return random_number;
}

void QtWidgetsApplication1::reverseArray() {
    int i = 0, j = 15 - 1;
    while (i < j) {
        int temp = hrl[i];
        hrl[i] = hrl[j];
        hrl[j] = temp;
        i++;
        j--;
    }
}

void QtWidgetsApplication1::shuffleArray(int arr[], int n) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr, arr + n, g);
}

void QtWidgetsApplication1::openDiffWindow()
{
    diffDialog = new QDialog(this);
    diff.setupUi(diffDialog);
    connect(&diff, &Ui::Dialog::level1Clicked, this, &QtWidgetsApplication1::handleLevel1);
    connect(&diff, &Ui::Dialog::level2Clicked, this, &QtWidgetsApplication1::handleLevel2);
    connect(&diff, &Ui::Dialog::level3Clicked, this, &QtWidgetsApplication1::handleLevel3);
    connect(&diff, &Ui::Dialog::level4Clicked, this, &QtWidgetsApplication1::handleLevel4);
    connect(&diff, &Ui::Dialog::handleCloseEvent, this, &QtWidgetsApplication1::handleCloseEvent);
    diffDialog->exec();
}

void QtWidgetsApplication1::save() {

}

void QtWidgetsApplication1::solve() {

}

void QtWidgetsApplication1::handleCloseEvent() {
    qDebug() << "clicked";
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel1() {
    /*qDebug() << "Level 1 clicked";*/
    levell = 20;
    levelr = 54;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel2() {
    /*qDebug() << "Level 2 clicked";*/
    levell = 54;
    levelr = 78;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel3() {
    /*qDebug() << "Level 3 clicked";*/
    levell = 78;
    levelr = 100;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel4() {
    /*qDebug() << "Level 4 clicked";*/
    levell = 100;
    levelr = 150;
    diffDialog->close();
}

void QtWidgetsApplication1::_1Clicked()
{
    BtnClicked(0);
}

void QtWidgetsApplication1::_2Clicked()
{
    BtnClicked(1);
}

void QtWidgetsApplication1::_3Clicked()
{
    BtnClicked(2);
}

void QtWidgetsApplication1::_4Clicked()
{
    BtnClicked(3);
}

void QtWidgetsApplication1::_5Clicked()
{
    BtnClicked(4);
}

void QtWidgetsApplication1::_6Clicked()
{
    BtnClicked(5);
}

void QtWidgetsApplication1::_7Clicked()
{
    BtnClicked(6);
}

void QtWidgetsApplication1::_8Clicked()
{
    BtnClicked(7);
}

void QtWidgetsApplication1::_9Clicked()
{
    BtnClicked(8);
}

void QtWidgetsApplication1::_10Clicked()
{
    BtnClicked(9);
}

void QtWidgetsApplication1::_11Clicked()
{
    BtnClicked(10);
}

void QtWidgetsApplication1::_12Clicked()
{
    BtnClicked(11);
}

void QtWidgetsApplication1::_13Clicked()
{
    BtnClicked(12);
}

void QtWidgetsApplication1::_14Clicked()
{
    BtnClicked(13);
}

void QtWidgetsApplication1::_15Clicked()
{
    BtnClicked(14);
}

void QtWidgetsApplication1::_16Clicked()
{
    BtnClicked(15);
}

void QtWidgetsApplication1::resetArray() {
    memcpy(hrl, target, sizeof(target));
}
