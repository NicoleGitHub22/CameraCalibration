#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderLbl = new QLabel(this);
    normalLbl = new QLabel(this);
    specLbl = new QLabel(this);
    mixedLbl = new QLabel(this);
    diffLbl = new QLabel(this);
    renderLbl->setGeometry(0,       0,      2*1920/3, 2*1200/3);
    normalLbl->setGeometry(2*1920/3, 0,     1920/4,    1200/4);
    specLbl->setGeometry(2*1920/3,  1200/4-50, 1920/4,    1200/4);
    mixedLbl->setGeometry(2*1920/3, 1200/2-100, 1920/4,    1200/4);
    diffLbl->setGeometry(2*1920/3,  3 * 1200/4-150, 1920/4,    1200/4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewRender(QImage rndr)
{
    renderLbl->setPixmap(QPixmap::fromImage(rndr.scaled(2*1920/3, 2*1200/3, Qt::KeepAspectRatio)));
}

void MainWindow::onNewDiff(QImage diff)
{
    diffLbl->setPixmap(QPixmap::fromImage(diff.scaled(1920/4, 1200/4-50, Qt::KeepAspectRatio)));
}

void MainWindow::onNewNormal(QImage n)
{
    normalLbl->setPixmap(QPixmap::fromImage(n.scaled(1920/4, 1200/4-50, Qt::KeepAspectRatio)));
}

void MainWindow::onNewSpec(QImage spec)
{
    specLbl->setPixmap(QPixmap::fromImage(spec.scaled(1920/4, 1200/4-50, Qt::KeepAspectRatio)));
}

void MainWindow::onNewMixed(QImage mix)
{
    mixedLbl->setPixmap(QPixmap::fromImage(mix.scaled(1920/4, 1200/4-50, Qt::KeepAspectRatio)));
}
