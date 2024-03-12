#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QLabel* renderLbl;
     QLabel* normalLbl;
     QLabel* specLbl;
     QLabel* mixedLbl;
     QLabel* diffLbl;
public slots:
     void onNewRender(QImage rndr);
     void onNewDiff(QImage diff);
     void onNewNormal(QImage n);
     void onNewSpec(QImage spec);
     void onNewMixed(QImage mix);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
