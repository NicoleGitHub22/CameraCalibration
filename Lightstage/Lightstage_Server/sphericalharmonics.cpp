//=============================================================================
// This class computes the spherical harmonics values for every monitor and
// stores them as image files.
//=============================================================================

#include "sphericalharmonics.h"
#include <cmath>
#include <iostream>
#include <tr1/cmath>
#include <QDebug>
#include <qimage.h>
#include <vector>

vector<double> SphericalHarmonics::Y(int l, int m, vector<Vector3D> &points)
{
    vector<double> res;

    for(auto &point : points){
        point.normalize();
        if(l == 0){
            res.insert(res.end(), 0.282095);
        }else if(l == 1){
            if(m == -1)     res.insert(res.end(), 0.488603 * point.y);
            else if(m == 0) res.insert(res.end(), 0.488603 * point.z);
            else if(m == 1) res.insert(res.end(), 0.488603 * point.x);
        }else if(l == 2){
            if(m == -2)     res.insert(res.end(), 1.092548 * point.y * point.x);
            else if(m == -1) res.insert(res.end(), 1.092548 * point.y * point.z);
            else if(m == 0) res.insert(res.end(), 0.946176 * point.z * point.z - 0.315392);
            else if(m == 1) res.insert(res.end(), 1.092548 * point.x * point.z);
            else if(m == 2) res.insert(res.end(), 0.546274 * (point.x * point.x - point.y * point.y));
        }else if(l == 3){
            if(m == -3)     res.insert(res.end(), -(sqrt(2)*sqrt(35) * point.y * (3 * point.x * point.x - point.y * point.y)) / (8 * sqrt(M_PI)));
            else if(m == -2)res.insert(res.end(), (sqrt(105) * point.x * point.y * point.z) / (2 * sqrt(M_PI)));
            else if(m == -1)res.insert(res.end(), -(sqrt(2)*sqrt(21) * point.y * (-1 + 5 * point.z * point.z)) / (8 * sqrt(M_PI)));
            else if(m == 0) res.insert(res.end(), (sqrt(7) * point.z * (5 * point.z * point.z - 3)) / (4 * sqrt(M_PI)));
            else if(m == 1) res.insert(res.end(), -(sqrt(2)*sqrt(21) * point.x * (-1 + 5 * point.z * point.z)) / (8 * sqrt(M_PI)));
            else if(m == 2) res.insert(res.end(), (sqrt(105) * (point.x * point.x - point.y * point.y) * point.z) / (4 * sqrt(M_PI)));
            else if(m == 3) res.insert(res.end(), -(sqrt(2)*sqrt(35) * point.x * (point.x * point.x - 3 * point.y * point.y)) / (8 * sqrt(M_PI)));
	}
    }
    return res;
}



void SphericalHarmonics::createSphericalHarmonics(int l, int m)
{
    //                      1
    //                  +--------+(600;-600;600)
    //                 /        /|
    //              2 /    4   / |
    // (-600;600;600)+--------+  |                          z
    //               |        | 6|                          |
    //               |   5    |  +                          +---  x
    //               |        | /                          /
    //               |        |/                           y
    //               +--------+(600;600;-600)
    //                   3

    vector<Vector3D> monitor1(1200 * 1200); // from (-600;-600;600) to (600;-600;-600)
    vector<Vector3D> monitor2(1200 * 1200); // from (-600;600;600) to (-600;-600;-600)
    vector<Vector3D> monitor3(1200 * 1200); // from (600;600;-600) to (-600;-600;-600)
    vector<Vector3D> monitor4(1200 * 1200); // from (-600;600;600) to (600;-600;600)
    vector<Vector3D> monitor5(1200 * 1200); // from (-600;600;600) to (600;600;-600)
    vector<Vector3D> monitor6(1200 * 1200); // from (600;600;-600) to (600;-600;600)

    for(int p = 0; p < 1200; p++){
        for(int q = 0; q < 1200; q++){
            /* Monitors are oriented like this:
             *
             *        4           3           6           2           4           1
             *        |           |           |           |           |           |
             *      +---+       +---+       +---+       +---+       +---+       +---+
             *   2<-| 1 |->6 1<-| 2 |->5 1<-| 3 |->5 1<-| 4 |->5 2<-| 5 |->6 3<-| 6 |->4
             *      +---+       +---+       +---+       +---+       +---+       +---+
             *        |           |           |           |           |           |
             *        3           4           2           6           3           5
             */
            monitor1[p + 1200 * q].x = p - 600;
            monitor1[p + 1200 * q].y = -600;
            monitor1[p + 1200 * q].z = 600 - q;

            monitor2[p + 1200 * q].x = -600;
            monitor2[p + 1200 * q].y = p - 600;
            monitor2[p + 1200 * q].z = q - 600;

            monitor3[p + 1200 * q].x = 600 - q;
            monitor3[p + 1200 * q].y = p - 600;
            monitor3[p + 1200 * q].z = -600;

            monitor4[p + 1200 * q].x = q - 600;
            monitor4[p + 1200 * q].y = p - 600;
            monitor4[p + 1200 * q].z = 600;

            monitor5[p + 1200 * q].x = p - 600;
            monitor5[p + 1200 * q].y = 600;
            monitor5[p + 1200 * q].z = 600 - q;

            monitor6[p + 1200 * q].x = 600;
            monitor6[p + 1200 * q].y = q - 600;
            monitor6[p + 1200 * q].z = p - 600;
        }
    }

    vector<vector<double>> SHs = {Y(l, m, monitor1),
                                  Y(l, m, monitor2),
                                  Y(l, m, monitor3),
                                  Y(l, m, monitor4),
                                  Y(l, m, monitor5),
                                  Y(l, m, monitor6)};
    if(l != 0){
      normalizeValues(SHs);
    }

    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 1200;
    QImage* images[6];
    QImage* images_INVERSE[6];
    QString imagePath = "../SphericalHarmonics/";

    for(int i = 0; i < 6; i++){
        images[i] = new QImage(SCREEN_WIDTH, SCREEN_HEIGHT, QImage::Format_Grayscale8);
        images_INVERSE[i] = new QImage(SCREEN_WIDTH, SCREEN_HEIGHT, QImage::Format_Grayscale8);
        for(int x=0; x < SCREEN_WIDTH; x++){
            for(int y=0; y < SCREEN_HEIGHT; y++){
                int col = std::max(0, std::min((int)(SHs[i][x + 1200*y] * 255), 255));
                float norm_fac = normBrightness(2 * (x / (float)SCREEN_WIDTH) - 1, 2 * (y / (float)SCREEN_HEIGHT) - 1, 0.1);
                images[i]->setPixelColor(x, y, QColor(col * norm_fac, col * norm_fac, col * norm_fac));
                images_INVERSE[i]->setPixelColor(x, y, QColor((255 - col) * norm_fac, (255 - col) * norm_fac, (255 - col) * norm_fac));
            }
        }
        images[i]->save(imagePath + "SPH-" + QString::number(l) + "-" + QString::number(m) + "-" + QString::number(i + 1) + ".bmp");
        images_INVERSE[i]->save(imagePath + "SPH--" + QString::number(l) + "-" + QString::number(m) + "-" + QString::number(i + 1) + ".bmp");
    }
}

void SphericalHarmonics::createGraceCathedralSphericalHarmonics()
{
    vector<Vector3D> monitor1(1200 * 1200); // from (-600;-600;600) to (600;-600;-600)
    vector<Vector3D> monitor2(1200 * 1200); // from (-600;600;600) to (-600;-600;-600)
    vector<Vector3D> monitor3(1200 * 1200); // from (600;600;-600) to (-600;-600;-600)
    vector<Vector3D> monitor4(1200 * 1200); // from (-600;600;600) to (600;-600;600)
    vector<Vector3D> monitor5(1200 * 1200); // from (-600;600;600) to (600;600;-600)
    vector<Vector3D> monitor6(1200 * 1200); // from (600;600;-600) to (600;-600;600)
    for(int p = 0; p < 1200; p++){
        for(int q = 0; q < 1200; q++){
            monitor1[p + 1200 * q].x = p - 600;
            monitor1[p + 1200 * q].y = -600;
            monitor1[p + 1200 * q].z = 600 - q;
            monitor2[p + 1200 * q].x = -600;
            monitor2[p + 1200 * q].y = p - 600;
            monitor2[p + 1200 * q].z = q - 600;
            monitor3[p + 1200 * q].x = 600 - q;
            monitor3[p + 1200 * q].y = p - 600;
            monitor3[p + 1200 * q].z = -600;
            monitor4[p + 1200 * q].x = q - 600;
            monitor4[p + 1200 * q].y = p - 600;
            monitor4[p + 1200 * q].z = 600;
            monitor5[p + 1200 * q].x = p - 600;
            monitor5[p + 1200 * q].y = 600;
            monitor5[p + 1200 * q].z = 600 - q;
            monitor6[p + 1200 * q].x = 600;
            monitor6[p + 1200 * q].y = q - 600;
            monitor6[p + 1200 * q].z = p - 600;
        }
    }
    vector<vector<double>> SH00 = {Y(0, 0, monitor1),
                                  Y(0, 0, monitor2),
                                  Y(0, 0, monitor3),
                                  Y(0, 0, monitor4),
                                  Y(0, 0, monitor5),
                                  Y(0, 0, monitor6)};
    vector<vector<double>> SH1_1 = {Y(1, -1, monitor1),
                                  Y(1, -1, monitor2),
                                  Y(1, -1, monitor3),
                                  Y(1, -1, monitor4),
                                  Y(1, -1, monitor5),
                                  Y(1, -1, monitor6)};
    vector<vector<double>> SH10 = {Y(1, 0, monitor1),
                                  Y(1, 0, monitor2),
                                  Y(1, 0, monitor3),
                                  Y(1, 0, monitor4),
                                  Y(1, 0, monitor5),
                                  Y(1, 0, monitor6)};
    vector<vector<double>> SH11 = {Y(1, 1, monitor1),
                                  Y(1, 1, monitor2),
                                  Y(1, 1, monitor3),
                                  Y(1, 1, monitor4),
                                  Y(1, 1, monitor5),
                                  Y(1, 1, monitor6)};
    vector<vector<double>> SH2_2 = {Y(2, -2, monitor1),
                                  Y(2, -2, monitor2),
                                  Y(2, -2, monitor3),
                                  Y(2, -2, monitor4),
                                  Y(2, -2, monitor5),
                                  Y(2, -2, monitor6)};
    vector<vector<double>> SH2_1 = {Y(2, -1, monitor1),
                                  Y(2, -1, monitor2),
                                  Y(2, -1, monitor3),
                                  Y(2, -1, monitor4),
                                  Y(2, -1, monitor5),
                                  Y(2, -1, monitor6)};

    vector<vector<double>> SH20 = {Y(2, 0, monitor1),
                                  Y(2, 0, monitor2),
                                  Y(2, 0, monitor3),
                                  Y(2, 0, monitor4),
                                  Y(2, 0, monitor5),
                                  Y(2, 0, monitor6)};

    vector<vector<double>> SH21 = {Y(2, 1, monitor1),
                                  Y(2, 1, monitor2),
                                  Y(2, 1, monitor3),
                                  Y(2, 1, monitor4),
                                  Y(2, 1, monitor5),
                                  Y(2, 1, monitor6)};

    vector<vector<double>> SH22 = {Y(2, 2, monitor1),
                                  Y(2, 2, monitor2),
                                  Y(2, 2, monitor3),
                                  Y(2, 2, monitor4),
                                  Y(2, 2, monitor5),
                                  Y(2, 2, monitor6)};

    normalizeValues(SH00);
    normalizeValues(SH1_1);
    normalizeValues(SH10);
    normalizeValues(SH11);
    normalizeValues(SH2_2);
    normalizeValues(SH2_1);
    normalizeValues(SH20);
    normalizeValues(SH21);
    normalizeValues(SH22);

    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 1200;
    QImage* images[6];
   // QImage* images_[6];// = new QImage(SCREEN_WIDTH, SCREEN_HEIGHT, QImage::Format_Grayscale8);
    QString imagePath = "../SphericalHarmonics/";

    for(int i = 0; i < 6; i++){
        images[i] = new QImage(SCREEN_WIDTH, SCREEN_HEIGHT, QImage::Format_RGB32);
        //images_[i] = new QImage(SCREEN_WIDTH, SCREEN_HEIGHT, QImage::Format_RGB32);
        for(int x=0; x < SCREEN_WIDTH; x++){
            for(int y=0; y < SCREEN_HEIGHT; y++){
               int red = 0.79 * SH00[i][x + 1200*y] * 255
            + 0.39 * SH1_1[i][x + 1200*y] * 255
            - 0.34 * SH10[i][x + 1200*y] * 255
            - 0.29 * SH11[i][x + 1200*y] * 255
            - 0.11 * SH2_2[i][x + 1200*y] * 255
            - 0.26 * SH2_1[i][x + 1200*y] * 255
            - 0.16 * SH20[i][x + 1200*y] * 255
            + 0.56 * SH21[i][x + 1200*y] * 255
            + 0.21 * SH22[i][x + 1200*y] * 255;
            int green = 0.44 * SH00[i][x + 1200*y] * 255
            + 0.35 * SH1_1[i][x + 1200*y] * 255
            - 0.18 * SH10[i][x + 1200*y] * 255
            - 0.06 * SH11[i][x + 1200*y] * 255
            - 0.05 * SH2_2[i][x + 1200*y] * 255
            - 0.22 * SH2_1[i][x + 1200*y] * 255
            - 0.09 * SH20[i][x + 1200*y] * 255
            + 0.21 * SH21[i][x + 1200*y] * 255
            - 0.05 * SH22[i][x + 1200*y] * 255;
            int blue = 0.54 * SH00[i][x + 1200*y] * 255
            + 0.60 * SH1_1[i][x + 1200*y] * 255
            - 0.27 * SH10[i][x + 1200*y] * 255
            + 0.01 * SH11[i][x + 1200*y] * 255
            - 0.12 * SH2_2[i][x + 1200*y] * 255
            - 0.47 * SH2_1[i][x + 1200*y] * 255
            - 0.15 * SH20[i][x + 1200*y] * 255
            + 0.14 * SH21[i][x + 1200*y] * 255
            - 0.30 * SH22[i][x + 1200*y] * 255;

                float norm_fac = normBrightness(2 * (x / (float)SCREEN_WIDTH) - 1, 2 * (y / (float)SCREEN_HEIGHT) - 1, 0.3);
                images[i]->setPixelColor(x, y, QColor(std::max(0,(int)(red * norm_fac)), std::max(0, (int)(green * norm_fac)), std::max(0,(int)(blue * norm_fac))));
               // images_[i]->setPixelColor(x, y, QColor(std::max(0,std::min(255,(int)(255 - red * norm_fac))),
                                                      // std::max(0, std::min(255,(int)(255 - green * norm_fac))),
                                                       //std::max(0,std::min(255,(int)(255 - blue * norm_fac)))));
               // qDebug() << red << green << blue;
            }
        }
        images[i]->save(imagePath + "GraceCathedralIlluminationPattern-" + QString::number(i + 1) + ".png");
       // images_[i]->save(imagePath + "GraceCathedralIlluminationPattern-" + QString::number(i + 1) + "_.png");
    }
}


Direction SphericalHarmonics::getAnglesFromPoint(Vector3D &point)
{
    double theta = atan(std::sqrt(point.x * point.x + point.y * point.y) / point.z);;
    //TODO was wenn x = 0 ist? nan error
    double phi = atan(point.y / point.x);
    return Direction(theta, phi);
}

int SphericalHarmonics::factorial(int x)
{
    return (x == 1 || x == 0) ? 1 : factorial(x - 1) * x;
}

/**
 * @brief shift and scale values in range 0-1
 * @param v
 */
void SphericalHarmonics::normalizeValues(vector<vector<double>> &v)
{
    double min = std::numeric_limits<double>::infinity();
    double max = -std::numeric_limits<double>::infinity();
    for(vector<double> &monitor : v){
        for(double &d : monitor){
            if(d > max)
                max = d;
            if(d < min)
                min = d;
        }
    }

    double delta = max - min;

    if(max != min){
        for(vector<double> &monitor : v){
            for(auto &d : monitor){
                d -= min; //shift
                d /= delta; //scale
            }
        }
    }
}

float SphericalHarmonics::normBrightness(float x, float y, float alpha)
{
    return 1 - (alpha / (float)(x * x + y * y + 1));
}

