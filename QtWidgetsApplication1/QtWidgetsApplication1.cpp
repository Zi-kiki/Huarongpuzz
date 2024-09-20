#pragma execution_character_set("utf-8")

#include "QtWidgetsApplication1.h"
#include "diff.h"
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

extern const QString none = "";
extern int hrl[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };

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


}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}

void QtWidgetsApplication1::BtnClicked(int index) {

    int directions[4] = { -1, 1, -4, 4 };

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

void QtWidgetsApplication1::openfile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*.*);;图像文件 (*.png *.jpg)"));
    if (!fileName.isEmpty()) {
        qDebug() << "选择的文件:" << fileName;
    }
}


void QtWidgetsApplication1::gen() {
    int dg = 0;
    openDiffWindow();
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
        QMessageBox::information(nullptr, "提示", "你赢了！", QMessageBox::Ok);
    }
}

int QtWidgetsApplication1::judgment()
{
    int i, j,sum = 0;
    for (i = 0;i < 15;i++)
    {
        for (j = i;j < 15;j++)
        {
            if (hrl[i] > hrl[j])
            {
                sum++;
            }
        }
    }
    return sum;
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
    diffDialog->exec();
}

void QtWidgetsApplication1::handleLevel1() {
    qDebug() << "Level 1 clicked";
    levell = 20;
    levelr = 54;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel2() {
    qDebug() << "Level 2 clicked";
    levell = 54;
    levelr = 78;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel3() {
    qDebug() << "Level 3 clicked";
    levell = 78;
    levelr = 100;
    diffDialog->close();
}

void QtWidgetsApplication1::handleLevel4() {
    qDebug() << "Level 4 clicked";
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