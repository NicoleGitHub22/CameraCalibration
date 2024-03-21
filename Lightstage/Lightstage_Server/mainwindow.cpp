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
    qDebug() << "calBtn_clicked 1";
    int delayClient1 = ui->delayClient1spinBox->value();
    int delayClient0 = ui->delayClient0spinBox->value();
    calibrate();
    setMainStatus("Calibrating...", false);
    ui->progressBar->setValue(0);
    qDebug() << "calBtn_clicked 2";
}

void MainWindow::on_scanBtn_clicked()
{
    qDebug() << "ScanBtn_clicked";
    int levelOfDetail = ui->LoDspinBox->value();
    int delayClient1 = ui->delayClient1spinBox->value();
    int delayClient0 = ui->delayClient0spinBox->value();
    scan(levelOfDetail);
    setMainStatus("Scanning...", false);
    ui->scan_progressBar->setValue(0);
    if(ui->client1ConnectedCB->isChecked() || ui->client2ConnectedCB->isChecked()){
       // ui->scanBtn->setEnabled(false);
    }
    qDebug() << "ScanBtn_clicked 2";
}

void MainWindow::on_delayClient0spinBox_editingFinished()
{
    qDebug() << "delayClient0spinBox_editingFinished 1";
    int delay = ui->delayClient0spinBox->value();
    int clientID = 0;
    setClientDelay(delay, clientID);
    qDebug() << "delayClient0spinBox_editingFinished 2";
}

void MainWindow::on_delayClient1spinBox_editingFinished()
{
    qDebug() << "delayClient1spinBox_editingFinished 1";
    int delay = ui->delayClient1spinBox->value();
    int clientID = 1;
    setClientDelay(delay, clientID);
    qDebug() << "delayClient1spinBox_editingFinished 2";
}

void MainWindow::onSimpleStateUpdate(QString state, bool error)
{
    qDebug() << "onSimpleStateUpdate 1";
    setMainStatus(state, error);
    qDebug() << "onSimpleStateUpdate 2";
}

void MainWindow::onCalibrated()
{
    qDebug() << "onCalibrated 1";
    ui->calBtn->setEnabled(true);
    qDebug() << "onCalibrated 2";
}

void MainWindow::onScanned()
{
    qDebug() << "onScanned 1";
    ui->scanBtn->setEnabled(true);
    qDebug() << "onScanned 2";
}

void MainWindow::onCalibrationFailed(QString errorMsgCal)
{
    qDebug() << "onCalibrationFailed 1";
    setMainStatus(errorMsgCal, true);
    ui->calBtn->setEnabled(true);
    qDebug() << "onCalibrationFailed 2";
}

void MainWindow::onScanFailed(QString errorMsg)
{
    qDebug() << "onScanFailed 1";
    setMainStatus(errorMsg, true);
    ui->scanBtn->setEnabled(true);
    qDebug() << "onScanFailed 2";
}

void MainWindow::onNewConnection(int clientID)
{
    qDebug() << "onNewConnection 1";
    if(clientID == 0)
        ui->client1ConnectedCB->setChecked(true);
    else if(clientID == 1)
        ui->client2ConnectedCB->setChecked(true);
    qDebug() << "onNewConnection 2";
}

void MainWindow::onDisconnect(int clientID)
{
    qDebug() << "onDisconnect 1";
    if(clientID == 0)
        ui->client1ConnectedCB->setChecked(false);
    else if(clientID == 1)
        ui->client2ConnectedCB->setChecked(false);
    qDebug() << "onDisconnect 2";
}

void MainWindow::onScanProgress(int progress)
{
    qDebug() << "onScanProgress 1";
    ui->scan_progressBar->setValue(progress);
    qDebug() << "onScanProgress 2";
}

void MainWindow::onCalProgress(int progress)
{
    qDebug() << "onCalProgress 1";
    ui->progressBar->setValue(progress);
    qDebug() << "onCalProgress 2";
}

void MainWindow::setMainStatus(QString message, bool warning)
{
    qDebug() << "setMainStatus 1";
    if(warning)
        ui->statusLbl->setStyleSheet("QLabel { color : red; }");
    else
        ui->statusLbl->setStyleSheet("QLabel { color : black; }");

    ui->statusLbl->setText("Status: " + message);
    qDebug() << "setMainStatus 2";
}

void MainWindow::on_stop_button_clicked()
{
    // Execute the stop_lightstage.sh script
        QProcess::execute("/bin/bash", {"../Build/Server/stop_lightstage.sh"});
}

