/*********** Computer Graphics *****************
 ********   Author:PengFei WU
 ********     Date:2017-11-02 18:52:20
 ********  Version:V7
 ******** ************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
