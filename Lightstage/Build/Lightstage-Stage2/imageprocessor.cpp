//=============================================================================
// Contains useful image manipulation algorithms and functions. Is responsible
// for computing normals, speculars, etc. from sh responses.
//=============================================================================

#include "imageprocessor.h"
#include <QDebug>
#include <math.h>
#include <bits/stdc++.h>

ImageProcessor::ImageProcessor()
{

}

QImage ImageProcessor::difference(QImage &a, QImage &b)
{
    if(a.height() != b.height() || a.width() != b.width()){
        qDebug() << "images do not have the same size";
    }

    QImage diff = QImage(a.width(), a.height(), QImage::Format_RGB32);

    for(int u = 0; u < a.width(); u++){
        for(int v = 0; v < a.height(); v++){
            int red = a.pixelColor(u, v).red() - b.pixelColor(u, v).red();
            int green = a.pixelColor(u, v).green() - b.pixelColor(u, v).green();
            int blue = a.pixelColor(u, v).blue() - b.pixelColor(u, v).blue();

            diff.setPixelColor(u, v, QColor(abs(red), abs(green), abs(blue)));
        }
    }

    return diff;
}

QImage ImageProcessor::subtract(QImage &a, QImage &b)
{
    if(a.height() != b.height() || a.width() != b.width()){
        qDebug() << "images do not have the same size";
    }

    QImage sub = QImage(a.width(), a.height(), QImage::Format_RGB32);

    for(int u = 0; u < a.width(); u++){
        for(int v = 0; v < a.height(); v++){
            int red = a.pixelColor(u, v).red() - b.pixelColor(u, v).red();
            int green = a.pixelColor(u, v).green() - b.pixelColor(u, v).green();
            int blue = a.pixelColor(u, v).blue() - b.pixelColor(u, v).blue();

            sub.setPixelColor(u, v, QColor(std::max(red, 0), std::max(green, 0), std::max(blue, 0)));
        }
    }

    return sub;
}

QImage ImageProcessor::sum(QImage &a, QImage &b)
{
    if(a.height() != b.height() || a.width() != b.width()){
        qDebug() << "images do not have the same size";
    }

    QImage sum = QImage(a.width(), a.height(), QImage::Format_RGB32);

    for(int u = 0; u < a.width(); u++){
        for(int v = 0; v < a.height(); v++){
            int red = a.pixelColor(u, v).red() + b.pixelColor(u, v).red();
            int green = a.pixelColor(u, v).green() + b.pixelColor(u, v).green();
            int blue = a.pixelColor(u, v).blue() + b.pixelColor(u, v).blue();

            sum.setPixelColor(u, v, QColor(std::min(red, 255), std::min(green, 255), std::min(blue, 255)));
        }
    }
    return sum;
}

QImage ImageProcessor::average(QImage images[], int size)
{
    QImage av = QImage(images[0].width(), images[0].height(), QImage::Format_RGB32);

    for(int u = 0; u < images[0].width(); u++){
        for(int v = 0; v < images[0].height(); v++){
            int red = 0;
            int green = 0;
            int blue = 0;
            for(int i = 0; i < size; i++){
                red += images[i].pixelColor(u, v).red();
                green += images[i].pixelColor(u, v).green();
                blue += images[i].pixelColor(u, v).blue();
            }
            av.setPixelColor(u, v, QColor(red/size, green/size, blue/size));
        }
    }
    return av;
}

QImage ImageProcessor::rgb2grayscale(QImage &img)
{
     QImage grayscale = QImage(img.width(), img.height(), QImage::Format_RGB32);

    for(int u = 0; u < img.width(); u++){
        for(int v = 0; v < img.height(); v++){
            int red = img.pixelColor(u, v).red();
            int green = img.pixelColor(u, v).green();
            int blue = img.pixelColor(u, v).blue();

            int gray = (red + green +blue) / 3;

            grayscale.setPixelColor(u, v, QColor(gray, gray, gray));
        }
    }
    return grayscale;
}

QImage ImageProcessor::addColor(QImage &img, int r, int g, int b)
{
    QImage img_colorized = QImage(img.width(), img.height(), QImage::Format_RGB32);

    for(int u = 0; u < img.width(); u++){
        for(int v = 0; v < img.height(); v++){
            int red = img.pixelColor(u, v).red();
            int green = img.pixelColor(u, v).green();
            int blue = img.pixelColor(u, v).blue();

            img_colorized.setPixelColor(u, v, QColor(std::min(red + r, 255), std::min(green + g, 255), std::min(blue + b, 255)));
        }
    }
    return img_colorized;
}

QImage ImageProcessor::normalMap(QImage SH1[], QImage SH1_[], int sizeSH1)
{
    QImage xR = subtract(SH1[0], SH1_[0]);
    QImage yR = subtract(SH1[1], SH1_[1]);
    QImage zR = subtract(SH1[2], SH1_[2]);
    QImage xGray = rgb2grayscale(xR);
    QImage yGray = rgb2grayscale(yR);
    QImage zGray = rgb2grayscale(zR);
    QImage normalMap = QImage(SH1[0].width(), SH1[0].height(), QImage::Format_RGB32);

    for(int u = 0; u < SH1[0].width(); u++){
        for(int v = 0; v < SH1[0].height(); v++){
            float red = std::max(0, xGray.pixelColor(u, v).red());
            float green = std::max(0, yGray.pixelColor(u, v).red());
            float blue = std::max(0, zGray.pixelColor(u, v).red());

            int len = sqrt(red * red + green * green + blue * blue);

            if(len == 0)
                normalMap.setPixelColor(u, v, QColor(0, 0, 0));
            else
                normalMap.setPixelColor(u, v, QColor(255*red/len, 255*green/len, 255*blue/len));
        }
    }
    return median_filter(normalMap, 1);
}

QImage ImageProcessor::albedo_mixed(QImage &Y00)
{
    return Y00;
}

QImage ImageProcessor::specular(QImage SH[], QImage SH_[], int &size)
{
    QImage spec = QImage(SH[0].width(), SH[0].height(), QImage::Format_RGB32);

    for(int u = 0; u < SH[0].width(); u++){
        for(int v = 0; v < SH[0].height(); v++){
            int sat_min = 255;
            int sat_max = 0;
            int sat_delta  = 0;
            for(int sh = 0; sh < size; sh++){
                int sat = 0;
                sat = abs(SH[sh].pixelColor(u, v).hsvSaturation() - SH_[sh].pixelColor(u, v).hsvSaturation());
                sat_min = sat_min > sat ? sat : sat_min;
                sat_max = sat_max < sat ? sat : sat_max;
            }

            sat_delta = abs(sat_max - sat_min);

            //if you want to implement a threshold
            float threshold = 0.0 * 255;
            if(sat_delta < threshold)
                sat_delta = 0;

            //maybe even  for each color channel seperately?
            spec.setPixelColor(u, v, QColor(sat_delta, sat_delta, sat_delta));
        }
    }
    return median_filter(spec, 1);
}

/*
 * Diffuse albedo = (1 / PI) * (D00 / Y00)
 *
 * D00 is the mixed albedo minus the specular albedo
 * Y00 the constant 0.5 * sqrt(1/pi)
 */
QImage ImageProcessor::albedo_diffuse(QImage &mixed, QImage &specular)
{
    QImage diff = QImage(mixed.width(), mixed.height(), QImage::Format_RGB32);

    float Y00 = 0.5 * sqrt(1/M_PI);

    for(int u = 0; u < mixed.width(); u++){
        for(int v = 0; v < mixed.height(); v++){
            int red = (1/M_PI) * (mixed.pixelColor(u, v).red() - specular.pixelColor(u, v).red())       / Y00;
            int green = (1/M_PI) * (mixed.pixelColor(u, v).green() - specular.pixelColor(u, v).green()) / Y00;
            int blue = (1/M_PI) * (mixed.pixelColor(u, v).blue() - specular.pixelColor(u, v).blue())    / Y00;

            diff.setPixelColor(u, v, QColor(std::max(std::min(red, 255), 0), std::max(std::min(green, 255), 0), std::max(std::min(blue, 255), 0)));
        }
    }
    return diff;
}

QImage ImageProcessor::median_filter(QImage &img, int kernelSize)
{
    QImage med = QImage(img.width(), img.height(), QImage::Format_RGB32);

    for(int u = kernelSize; u < img.width() - kernelSize; u++){
        for(int v = kernelSize; v < img.height() - kernelSize; v++){

            int r[(kernelSize * 2 + 1) * (kernelSize * 2 + 1)];
            int g[(kernelSize * 2 + 1) * (kernelSize * 2 + 1)];
            int b[(kernelSize * 2 + 1) * (kernelSize * 2 + 1)];

            for(int x = 0; x < 2 * kernelSize + 1; x++){
                for(int y = 0; y < 2 * kernelSize + 1; y++){
                    r[x + (kernelSize * 2 + 1) * y] = img.pixelColor(u - kernelSize + x, v - kernelSize + y).red();
                    g[x + (kernelSize * 2 + 1) * y] = img.pixelColor(u - kernelSize + x, v - kernelSize + y).green();
                    b[x + (kernelSize * 2 + 1) * y] = img.pixelColor(u - kernelSize + x, v - kernelSize + y).blue();
                }
            }

            std::sort(r, r + (2 * kernelSize + 1) * (2 * kernelSize + 1));
            std::sort(g, g + (2 * kernelSize + 1) * (2 * kernelSize + 1));
            std::sort(b, b + (2 * kernelSize + 1) * (2 * kernelSize + 1));

            int red = r[(2 * kernelSize + 1) * (2 * kernelSize + 1) / 2];
            int green = g[(2 * kernelSize + 1) * (2 * kernelSize + 1) / 2];
            int blue =b[(2 * kernelSize + 1) * (2 * kernelSize + 1) / 2];

            med.setPixelColor(u, v, QColor(std::max(red, 0), std::max(green, 0), std::max(blue, 0)));
        }
    }
    return med;
}
