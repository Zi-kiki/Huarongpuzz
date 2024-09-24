#pragma execution_character_set("utf-8")

#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    #include <QTextCodec>
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    #endif
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
}
