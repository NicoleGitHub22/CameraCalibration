#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QImage>

class ImageProcessor : public QObject
{
    Q_OBJECT
public:
    ImageProcessor();
    QImage difference(QImage &a, QImage &b);
    QImage subtract(QImage &a, QImage &b);
    QImage sum(QImage &a, QImage &b);
    QImage average(QImage images[], int size);
    QImage rgb2grayscale(QImage &img);
    QImage addColor(QImage &img, int r, int g, int b);
    QImage normalMap(QImage SH1[], QImage SH1_[], int sizeSH1);
    QImage albedo_mixed(QImage &Y00);
    QImage specular(QImage SH[], QImage SH_[], int &size);
    QImage albedo_diffuse(QImage &mixed, QImage &specular);
    QImage median_filter(QImage &img, int kernelSize);
};

#endif // IMAGEPROCESSOR_H
