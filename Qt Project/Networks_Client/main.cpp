#include "mainwindow.h"
#include <QApplication>

#ifndef int32_t
#define int32_t qint32
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
