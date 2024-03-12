#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_scanBtn_clicked();
    void on_calBtn_clicked();
    void on_delayClient0spinBox_editingFinished();
    void on_delayClient1spinBox_editingFinished();
    void on_stop_button_clicked();

public slots:
    void onSimpleStateUpdate(QString state, bool error);
    void onCalibrated();
    void onScanned();
    void onCalibrationFailed();
    void onScanFailed(QString errorMsg);
    void onNewConnection(int clientID);
    void onDisconnect(int clientID);
    void onScanProgress(int progress);

private:
    Ui::MainWindow *ui;
    void setMainStatus(QString message, bool warning);

signals:
    void calibrate();
    void scan(int levelOfDetail = 0);
    void setClientDelay(int delay, int clientID);
};

#endif // MAINWINDOW_H
