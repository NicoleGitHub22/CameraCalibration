//=============================================================================
// Displays an sh image on a lightstage-monitor.
//=============================================================================

#include "lightstagewindow.h"
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QTimer>

#include <stdio.h>
#include <stdlib.h>

QString IMAGE_PATH = "/home/bretznic/Documents/Lightstage/SphericalHarmonics/";


LightstageWindow::LightstageWindow(QWidget *parent) : QWidget(parent)
{
    m_label = new QLabel(this);

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);

    QPixmap image;
    image.load(IMAGE_PATH + "standby.jpg");
    m_label->setPixmap(image.scaled(1200, 1200));

    this->setGeometry(0, 0, 1920, 1200);
    this->showFullScreen();
}

void LightstageWindow::showPixmap(QPixmap &image){

    m_label->setPixmap(image);
}
