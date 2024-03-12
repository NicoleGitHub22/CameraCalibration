#ifndef LIGHSTAGEWINDOW_H
#define LIGHSTAGEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QColor>

class LightstageWindow : public QWidget
{
    Q_OBJECT
 public:
    explicit LightstageWindow(QWidget *parent = nullptr);
    void showPixmap(QPixmap &image);
 private:
 QLabel *m_label;
};

#endif // LIGHSTAGEWINDOW_H
