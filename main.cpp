#include "mainwindow.h"
#include <QApplication>
#include<QDialog>
#include<QLabel>
#include"mywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Mywindow d;
    w.show();
    return a.exec();
}
