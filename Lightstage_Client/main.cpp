#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string clientID(argv[1]);
    int screenShift = (clientID == "0") ? 1920 : 0;

    Client* client = new Client(NULL, screenShift, clientID);

    ///**************************************************************
    ///**                  DEBUG INFORMATION                       **
    ///**************************************************************

    int screenCount = QApplication::desktop()->screenCount();
    QRect screenres = QApplication::desktop()->screenGeometry(-1);

    qDebug() << "*** LIGHTSTAGE INFORMATION ***";
    //qDebug() << "Shifting screens: " << screenShift;
    qDebug() << "Number of detected monitors: " << screenCount;
    //qDebug() << "monitor res: " << screenres;

    ///**************************************************************

    return a.exec();
}
