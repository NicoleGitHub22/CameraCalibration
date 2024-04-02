#include "mainwindow.h"
#include <QApplication>
#include "renderer.h"
#include <QTimer>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    Renderer renderer;
    w.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &renderer, SLOT(onRender()));
    timer.setInterval(10000); //arbitrarily chosen
    timer.start();
    QObject::connect(&renderer, &Renderer::newRender, &w, &MainWindow::onNewRender);
    QObject::connect(&renderer, &Renderer::newDiffuse, &w, &MainWindow::onNewDiff);
    QObject::connect(&renderer, &Renderer::newMixed, &w, &MainWindow::onNewMixed);
    QObject::connect(&renderer, &Renderer::newNormal, &w, &MainWindow::onNewNormal);
    QObject::connect(&renderer, &Renderer::newSpec, &w, &MainWindow::onNewSpec);

    return app.exec();
}


