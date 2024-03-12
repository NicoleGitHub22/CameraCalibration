/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *firstScreenFrame;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_5;
    QSpinBox *delayClient0spinBox;
    QCheckBox *client1ConnectedCB;
    QFrame *secondScreenFrame;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_6;
    QSpinBox *delayClient1spinBox;
    QCheckBox *client2ConnectedCB;
    QFrame *operationsFrame;
    QFrame *scanFrame;
    QPushButton *scanBtn;
    QProgressBar *scan_progressBar;
    QLabel *LoDlabel;
    QSpinBox *LoDspinBox;
    QFrame *calFrame;
    QPushButton *calBtn;
    QProgressBar *progressBar;
    QPushButton *stop_button;
    QLabel *statusLbl;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(693, 498);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        firstScreenFrame = new QFrame(centralWidget);
        firstScreenFrame->setObjectName(QString::fromUtf8("firstScreenFrame"));
        firstScreenFrame->setGeometry(QRect(60, 10, 180, 141));
        firstScreenFrame->setFrameShape(QFrame::StyledPanel);
        firstScreenFrame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(firstScreenFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 110, 89, 25));
        pushButton->setCheckable(true);
        layoutWidget = new QWidget(firstScreenFrame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 101, 103));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        delayClient0spinBox = new QSpinBox(layoutWidget);
        delayClient0spinBox->setObjectName(QString::fromUtf8("delayClient0spinBox"));
        delayClient0spinBox->setMaximum(1000);

        verticalLayout->addWidget(delayClient0spinBox);

        client1ConnectedCB = new QCheckBox(layoutWidget);
        client1ConnectedCB->setObjectName(QString::fromUtf8("client1ConnectedCB"));
        client1ConnectedCB->setEnabled(false);
        client1ConnectedCB->setCheckable(true);
        client1ConnectedCB->setChecked(false);

        verticalLayout->addWidget(client1ConnectedCB);

        secondScreenFrame = new QFrame(centralWidget);
        secondScreenFrame->setObjectName(QString::fromUtf8("secondScreenFrame"));
        secondScreenFrame->setGeometry(QRect(250, 10, 180, 141));
        secondScreenFrame->setFrameShape(QFrame::StyledPanel);
        secondScreenFrame->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(secondScreenFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 110, 89, 25));
        pushButton_2->setCheckable(true);
        layoutWidget1 = new QWidget(secondScreenFrame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 101, 103));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        delayClient1spinBox = new QSpinBox(layoutWidget1);
        delayClient1spinBox->setObjectName(QString::fromUtf8("delayClient1spinBox"));
        delayClient1spinBox->setMaximum(1000);

        verticalLayout_2->addWidget(delayClient1spinBox);

        client2ConnectedCB = new QCheckBox(layoutWidget1);
        client2ConnectedCB->setObjectName(QString::fromUtf8("client2ConnectedCB"));
        client2ConnectedCB->setEnabled(false);
        client2ConnectedCB->setTristate(false);

        verticalLayout_2->addWidget(client2ConnectedCB);

        operationsFrame = new QFrame(centralWidget);
        operationsFrame->setObjectName(QString::fromUtf8("operationsFrame"));
        operationsFrame->setGeometry(QRect(60, 190, 561, 211));
        operationsFrame->setFrameShape(QFrame::StyledPanel);
        operationsFrame->setFrameShadow(QFrame::Raised);
        scanFrame = new QFrame(operationsFrame);
        scanFrame->setObjectName(QString::fromUtf8("scanFrame"));
        scanFrame->setGeometry(QRect(340, 10, 211, 191));
        scanFrame->setFrameShape(QFrame::StyledPanel);
        scanFrame->setFrameShadow(QFrame::Raised);
        scanBtn = new QPushButton(scanFrame);
        scanBtn->setObjectName(QString::fromUtf8("scanBtn"));
        scanBtn->setGeometry(QRect(30, 110, 151, 41));
        scan_progressBar = new QProgressBar(scanFrame);
        scan_progressBar->setObjectName(QString::fromUtf8("scan_progressBar"));
        scan_progressBar->setGeometry(QRect(10, 160, 191, 23));
        scan_progressBar->setValue(0);
        LoDlabel = new QLabel(scanFrame);
        LoDlabel->setObjectName(QString::fromUtf8("LoDlabel"));
        LoDlabel->setGeometry(QRect(30, 60, 111, 17));
        LoDspinBox = new QSpinBox(scanFrame);
        LoDspinBox->setObjectName(QString::fromUtf8("LoDspinBox"));
        LoDspinBox->setGeometry(QRect(30, 80, 111, 26));
        LoDspinBox->setMaximum(3);
        calFrame = new QFrame(operationsFrame);
        calFrame->setObjectName(QString::fromUtf8("calFrame"));
        calFrame->setGeometry(QRect(10, 10, 211, 191));
        calFrame->setFrameShape(QFrame::StyledPanel);
        calFrame->setFrameShadow(QFrame::Raised);
        calBtn = new QPushButton(calFrame);
        calBtn->setObjectName(QString::fromUtf8("calBtn"));
        calBtn->setGeometry(QRect(30, 110, 151, 41));
        progressBar = new QProgressBar(calFrame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 160, 191, 23));
        progressBar->setValue(0);
        stop_button = new QPushButton(operationsFrame);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setGeometry(QRect(230, 164, 101, 31));
        statusLbl = new QLabel(centralWidget);
        statusLbl->setObjectName(QString::fromUtf8("statusLbl"));
        statusLbl->setGeometry(QRect(260, 410, 191, 20));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(440, 10, 180, 141));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 131, 17));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 50, 101, 17));
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 50, 48, 26));
        MainWindow->setCentralWidget(centralWidget);
        operationsFrame->raise();
        firstScreenFrame->raise();
        secondScreenFrame->raise();
        statusLbl->raise();
        frame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Client 1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Delay(ms):", nullptr));
        client1ConnectedCB->setText(QCoreApplication::translate("MainWindow", "connected", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Client 2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Delay(ms):", nullptr));
        client2ConnectedCB->setText(QCoreApplication::translate("MainWindow", "connected", nullptr));
        scanBtn->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        LoDlabel->setText(QCoreApplication::translate("MainWindow", "Level of Detail", nullptr));
        calBtn->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
        stop_button->setText(QCoreApplication::translate("MainWindow", "Stop Program", nullptr));
        statusLbl->setText(QCoreApplication::translate("MainWindow", "Status: Ready.", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Camera Settings:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Exposure(ms):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
