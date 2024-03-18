#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <cstdlib>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calBtn_clicked()
{
    int delayClient1 = ui->delayClient1spinBox->value();
    int delayClient0 = ui->delayClient0spinBox->value();
    calibrate();
    setMainStatus("Calibrating...", false);

}

void MainWindow::on_scanBtn_clicked()
{
    int levelOfDetail = ui->LoDspinBox->value();
    int delayClient1 = ui->delayClient1spinBox->value();
    int delayClient0 = ui->delayClient0spinBox->value();
    scan(levelOfDetail);
    setMainStatus("Scanning...", false);
    ui->scan_progressBar->setValue(0);
    if(ui->client1ConnectedCB->isChecked() || ui->client2ConnectedCB->isChecked()){
       // ui->scanBtn->setEnabled(false);
    }
}

void MainWindow::on_delayClient0spinBox_editingFinished()
{
    int delay = ui->delayClient0spinBox->value();
    int clientID = 0;
    setClientDelay(delay, clientID);
}

void MainWindow::on_delayClient1spinBox_editingFinished()
{
    int delay = ui->delayClient1spinBox->value();
    int clientID = 1;
    setClientDelay(delay, clientID);
}

void MainWindow::onSimpleStateUpdate(QString state, bool error)
{
    setMainStatus(state, error);
}

void MainWindow::onCalibrated()
{
    ui->calBtn->setEnabled(true);
}

void MainWindow::onScanned()
{
    ui->scanBtn->setEnabled(true);
}

void MainWindow::onCalibrationFailed(QString errorMsgCal)
{
    setMainStatus(errorMsgCal, true);
    ui->calBtn->setEnabled(true);
}

void MainWindow::onScanFailed(QString errorMsg)
{
     setMainStatus(errorMsg, true);
    ui->scanBtn->setEnabled(true);
}

void MainWindow::onNewConnection(int clientID)
{
    if(clientID == 0)
        ui->client1ConnectedCB->setChecked(true);
    else if(clientID == 1)
        ui->client2ConnectedCB->setChecked(true);
}

void MainWindow::onDisconnect(int clientID)
{
    if(clientID == 0)
        ui->client1ConnectedCB->setChecked(false);
    else if(clientID == 1)
        ui->client2ConnectedCB->setChecked(false);
}

void MainWindow::onScanProgress(int progress)
{
    ui->scan_progressBar->setValue(progress);
}

void MainWindow::setMainStatus(QString message, bool warning)
{
    if(warning)
        ui->statusLbl->setStyleSheet("QLabel { color : red; }");
    else
        ui->statusLbl->setStyleSheet("QLabel { color : black; }");

    ui->statusLbl->setText("Status: " + message);
}

void MainWindow::on_stop_button_clicked()
{
    // Execute the stop_lightstage.sh script
        QProcess::execute("/bin/bash", {"../Build/Server/stop_lightstage.sh"});
}

