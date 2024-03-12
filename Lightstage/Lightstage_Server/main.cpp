#include "mainwindow.h"
#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server server;
    MainWindow w;
    w.show();

    QObject::connect(&server, &Server::newConnection, &w, &MainWindow::onNewConnection);
    QObject::connect(&server, &Server::disconnect, &w, &MainWindow::onDisconnect);

    QObject::connect(&w, &MainWindow::calibrate, &server, &Server::onCalibrate);
    QObject::connect(&w, &MainWindow::scan,  &server, &Server::onScan);

    QObject::connect(&server, &Server::scanned, &w, &MainWindow::onScanned);
    QObject::connect(&server, &Server::calibrated, &w, &MainWindow::onCalibrated);

    QObject::connect(&server, &Server::scanFailed, &w, &MainWindow::onScanFailed);

    QObject::connect(&server, &Server::scanProgress, &w, &MainWindow::onScanProgress);

    QObject::connect(&w, &MainWindow::setClientDelay, &server, &Server::onClientDelayChanged);

    QObject::connect(&server, &Server::simpleStateUpdate, &w, &MainWindow::onSimpleStateUpdate);

    return a.exec();
}
