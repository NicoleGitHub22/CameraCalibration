#include "renderer.h"
#include <QDebug>
#include <QTimer>

Renderer::Renderer(QObject *parent) : QObject(parent)
{
    //add lights to the scene. For orientation:
    //   y
    //   |
    //   +-- z
    //  /
    // x
    //TODO: fix the coordinate system in the renderer! z and y axis should be switched.
    lights = {Light(Vector3D(0, 0.5, 1), 10, QColor(255, 255, 255))};

    //Set the render area:
    //TODO: handle input outside the image size, clamp values
    renderArea.init(800, 250, 1600, 1050);
    //renderArea.init(0, 0, 1920, 1080);//<-no render area
}

QImage Renderer::render(QImage &diffuse, QImage &normals, vector<Light> &lights, QImage &specular)
{
    QImage renderImg = QImage(renderArea.xEnd - renderArea.xStart, renderArea.yEnd- renderArea.yStart, QImage::Format_RGB32);

    for(int u = renderArea.xStart; u < renderArea.xEnd; u++){
        for(int v = renderArea.yStart; v < renderArea.yEnd; v++){

            //float len = normals.pixelColor(u, v).red() + normals.pixelColor(u, v).green() + normals.pixelColor(u, v).blue();
            vector<double> normal = {(double)normals.pixelColor(u, v).red() /255,
                                     (double)normals.pixelColor(u, v).green() / 255,
                                     (double)normals.pixelColor(u, v).blue() / 255};
            QColor color = QColor(0,0,0);

            for(Light &light : lights){
                vector<double> d_i = {light.position.x, light.position.y, light.position.z};

                float theta_i = inner_product(begin(d_i), end(d_i), begin(normal), 0.0);            
                //is the light behind the surface? if yes, skip this lightsoure
                if(theta_i <= 0){
                     color.setRgb(0,0,0);
                     continue;
                }
                //assume a camera angle (has to be calibrated for more precision)
                vector<double> camera_dir = {-1, -0.5, -1};
                float theta_r = inner_product(begin(camera_dir), end(camera_dir), begin(normal), 0.0);

                double diffuse_r = diffuse.pixelColor(u, v).red();
                double diffuse_g = diffuse.pixelColor(u, v).green();
                double diffuse_b = diffuse.pixelColor(u, v).blue();
                //compute halfway-vector h
                Vector3D x, y;
                vector<double> h = x.fromStdVector(normal).add(y.fromStdVector(d_i)).normalize().toStdVector();

                float delta = inner_product(begin(normal), end(normal), begin(h), 0.0) / 180.0 * M_PI;
                float p_s =  (float)specular.pixelColor(u, v).red() / 255;
                float p_d = (diffuse_r + diffuse_g + diffuse_b)/(3.0 * 255);
                //chose alpha arbitrarily
                float alpha = 0.1;

                float ward = Ward(theta_i, theta_r, delta, p_d, p_s, alpha);

                //render final pixel color
                int red =   diffuse_r * ((double)light.color.red() /255)   * light.intensity * ward * sin(theta_i) * cos(theta_i);
                int green = diffuse_g * ((double)light.color.green() /255) * light.intensity * ward * sin(theta_i) * cos(theta_i);
                int blue =  diffuse_b * ((double)light.color.blue()/255)   * light.intensity * ward * sin(theta_i) * cos(theta_i);
                color.setRgb(min(max(red + color.red(), 0), 255),
                             min(max(green + color.green(), 0), 255),
                             min(max(blue + color.blue(), 0), 255));
            }
            renderImg.setPixelColor(u - renderArea.xStart, v - renderArea.yStart, color);
        }
    }
    return renderImg;
}

/**
 * @brief Renderer::Ward    Ward model for isotropic materials.
 *                          p_d + p_s must be <= 1.
 * @param theta_i   incoming light angle
 * @param theta_r   outgoing light angle
 * @param delta     angle between n and halfvector h
 * @param p_d       diffuse factor
 * @param p_s       specular factor
 * @param alpha     roughness value. Usually between 0.05 and 0.2
 * @return
 */
float Renderer::Ward(float theta_i, float theta_r, float delta, float p_d, float p_s, float alpha)
{

    return (p_d / M_PI) + (p_s / sqrt(cos(theta_i) * cos(theta_r))) * ((exp(-pow(tan(delta / (alpha * alpha)), 2))) / (4.0 * M_PI * alpha * alpha));
}

//Render the object with the coefficients for the Grace Cathedral illumination provided by Ramamoorthi[2001]
QImage Renderer::RenderGraceCathedral(QImage &Y00, QImage Y1m[], QImage Y1m_[], QImage Y2m[], QImage Y2m_[]){

    QImage graceCat = QImage(Y00.width(), Y00.height(), QImage::Format_RGB32);
	//switch y and z? so index 2 and 1
    QImage GY00 = imageProcessor.rgb2grayscale(Y00);
    QImage GY1m[3];
    GY1m[0] = imageProcessor.rgb2grayscale(Y1m[0]);
    GY1m[1] = imageProcessor.rgb2grayscale(Y1m[1]);
    GY1m[2] = imageProcessor.rgb2grayscale(Y1m[2]);
    QImage GY1m_[3];
    GY1m_[0] = imageProcessor.rgb2grayscale(Y1m_[0]);
    GY1m_[1] = imageProcessor.rgb2grayscale(Y1m_[1]);
    GY1m_[2] = imageProcessor.rgb2grayscale(Y1m_[2]);
    QImage GY2m[5];
    GY2m[0] = imageProcessor.rgb2grayscale(Y2m[0]);
    GY2m[1] = imageProcessor.rgb2grayscale(Y2m[1]);
    GY2m[2] = imageProcessor.rgb2grayscale(Y2m[2]);
    GY2m[3] = imageProcessor.rgb2grayscale(Y2m[3]);
    GY2m[4] = imageProcessor.rgb2grayscale(Y2m[4]);
    QImage GY2m_[5];
    GY2m_[0] = imageProcessor.rgb2grayscale(Y2m_[0]);
    GY2m_[1] = imageProcessor.rgb2grayscale(Y2m_[1]);
    GY2m_[2] = imageProcessor.rgb2grayscale(Y2m_[2]);
    GY2m_[3] = imageProcessor.rgb2grayscale(Y2m_[3]);
    GY2m_[4] = imageProcessor.rgb2grayscale(Y2m_[4]);

    for(int u = 0; u < Y00.width(); u++){
        for(int v = 0; v < Y00.height(); v++){

            int red = 0.79 * GY00.pixelColor(u,v).red()
            + 0.39 * (GY1m[0].pixelColor(u,v).red() - GY1m_[0].pixelColor(u,v).red())
            - 0.34 * (GY1m[1].pixelColor(u,v).red() - GY1m_[1].pixelColor(u,v).red())
            - 0.29 * (GY1m[2].pixelColor(u,v).red() - GY1m_[2].pixelColor(u,v).red())
            - 0.11 * (GY2m[0].pixelColor(u,v).red() - GY2m_[0].pixelColor(u,v).red())
            - 0.26 * (GY2m[1].pixelColor(u,v).red() - GY2m_[1].pixelColor(u,v).red())
            - 0.16 * (GY2m[2].pixelColor(u,v).red() - GY2m_[2].pixelColor(u,v).red())
            + 0.56 * (GY2m[3].pixelColor(u,v).red() - GY2m_[3].pixelColor(u,v).red())
            + 0.21 * (GY2m[4].pixelColor(u,v).red() - GY2m_[4].pixelColor(u,v).red());
            int green = 0.44 * GY00.pixelColor(u,v).green()
            + 0.35 * (GY1m[0].pixelColor(u,v).green() - GY1m_[0].pixelColor(u,v).green())
            - 0.18 * (GY1m[1].pixelColor(u,v).green() - GY1m_[1].pixelColor(u,v).green())
            - 0.06 * (GY1m[2].pixelColor(u,v).green() - GY1m_[2].pixelColor(u,v).green())
            - 0.05 * (GY2m[0].pixelColor(u,v).green() - GY2m_[0].pixelColor(u,v).green())
            - 0.22 * (GY2m[1].pixelColor(u,v).green() - GY2m_[1].pixelColor(u,v).green())
            - 0.09 * (GY2m[2].pixelColor(u,v).green() - GY2m_[2].pixelColor(u,v).green())
            + 0.21 * (GY2m[3].pixelColor(u,v).green() - GY2m_[3].pixelColor(u,v).green())
            - 0.05 * (GY2m[4].pixelColor(u,v).green() - GY2m_[4].pixelColor(u,v).green());
            int blue = 0.54 * GY00.pixelColor(u,v).blue()
            + 0.60 * (GY1m[0].pixelColor(u,v).blue() - GY1m_[0].pixelColor(u,v).blue())
            - 0.27 * (GY1m[1].pixelColor(u,v).blue() - GY1m_[1].pixelColor(u,v).blue())
            + 0.01 * (GY1m[2].pixelColor(u,v).blue() - GY1m_[2].pixelColor(u,v).blue())
            - 0.12 * (GY2m[0].pixelColor(u,v).blue() - GY2m_[0].pixelColor(u,v).blue())
            - 0.47 * (GY2m[1].pixelColor(u,v).blue() - GY2m_[1].pixelColor(u,v).blue())
            - 0.15 * (GY2m[2].pixelColor(u,v).blue() - GY2m_[2].pixelColor(u,v).blue())
            + 0.14 * (GY2m[3].pixelColor(u,v).blue() - GY2m_[3].pixelColor(u,v).blue())
            - 0.30 * (GY2m[4].pixelColor(u,v).blue() - GY2m_[4].pixelColor(u,v).blue());

            graceCat.setPixelColor(u, v, QColor(std::max(std::min(red, 255), 0), std::max(std::min(green, 255), 0), std::max(std::min(blue, 255), 0)));
        }
    }
    return graceCat;
}


int frame = 0;
void Renderer::onRender()
{
            auto start = high_resolution_clock::now();
    ImageProcessor imageProcessor;
    //where the scans are located:
    QString filepath = "/home/bretznic/Documents/Lightstage/Build/Server/FINAL_DIFF2 (copy)/";
    QImage n, specular, mixed, diff, rndr;
	//testrenders
    QImage graceCatRdr;

    QImage Y00;
    Y00.load(filepath + "0-0.ppm");

    int sizeY1m = 3;
    QImage Y1m[sizeY1m], Y1m_[sizeY1m];
    Y1m[0].load(filepath + "1--1.ppm");
    Y1m_[0].load(filepath + "-1--1.ppm");
    Y1m[1].load(filepath + "1-0.ppm");
    Y1m_[1].load(filepath + "-1-0.ppm");
    Y1m[2].load(filepath + "1-1.ppm");
    Y1m_[2].load(filepath + "-1-1.ppm");

    //ADD FOR TAKING AVERAGE VALUES OF MULTIPLE SCANS
    //take average of 5 scans
//  int averageNumber = 5;
//    QImage as[averageNumber], bs[averageNumber], cs[averageNumber], a_s[averageNumber], b_s[averageNumber], c_s[averageNumber];
//    for(int i = 0; i < averageNumber; i ++){
//        as[i].load(filepath + "R2"+ QString::number(i + 1) + "/1-0.ppm");
//        bs[i].load(filepath + "R2"+ QString::number(i + 1) + "/1--1.ppm");
//        cs[i].load(filepath + "R2"+ QString::number(i + 1) + "/1-1.ppm");
//        a_s[i].load(filepath + "R2"+ QString::number(i + 1) + "/-1-0.ppm");
//        b_s[i].load(filepath + "R2"+ QString::number(i + 1) + "/-1--1.ppm");
//        c_s[i].load(filepath + "R2"+ QString::number(i + 1) + "/-1-1.ppm");
//    }
//    Y1m[1] = imageProcessor.average(as, averageNumber);
//    Y1m[0] = imageProcessor.average(bs, averageNumber);
//    Y1m[2] = imageProcessor.average(cs, averageNumber);
//    Y1m_[1] = imageProcessor.average(a_s, averageNumber);
//    Y1m_[0] = imageProcessor.average(b_s, averageNumber);
//    Y1m_[2] = imageProcessor.average(c_s, averageNumber);

    int sizeY2m = 5;
    QImage Y2m[sizeY2m], Y2m_[sizeY2m];
    Y2m[0].load(filepath + "2--2.ppm");
    Y2m_[0].load(filepath + "-2--2.ppm");
    Y2m[1].load(filepath + "2--1.ppm");
    Y2m_[1].load(filepath + "-2--1.ppm");
    Y2m[2].load(filepath + "2-0.ppm");
    Y2m_[2].load(filepath + "-2-0.ppm");
    Y2m[3].load(filepath + "2-1.ppm");
    Y2m_[3].load(filepath + "-2-1.ppm");
    Y2m[4].load(filepath + "2-2.ppm");
    Y2m_[4].load(filepath + "-2-2.ppm");

    int sizeY3m = 7;
    QImage Y3m[sizeY3m], Y3m_[sizeY3m];
    for(int i = 0; i < 5; i++){
        Y3m[0].load(filepath + "3-0.ppm");
        Y3m_[0].load(filepath + "-3-0.ppm");
        Y3m[1].load(filepath + "3-1.ppm");
        Y3m_[1].load(filepath + "-3-1.ppm");
        Y3m[2].load(filepath + "3--1.ppm");
        Y3m_[2].load(filepath + "-3--1.ppm");
        Y3m[3].load(filepath + "3--2.ppm");
        Y3m_[3].load(filepath + "-3--2.ppm");
        Y3m[4].load(filepath + "3-2.ppm");
        Y3m_[4].load(filepath + "-3-2.ppm");
        Y3m[5].load(filepath + "3--3.ppm");
        Y3m_[5].load(filepath + "-3--3.ppm");
        Y3m[6].load(filepath + "3-3.ppm");
        Y3m_[6].load(filepath + "-3-3.ppm");
    }

    //take average of 5 scans
//    QImage as2[averageNumber], bs2[averageNumber], cs2[averageNumber], ds2[averageNumber], es2[averageNumber], fs2[averageNumber], gs2[averageNumber],
//            a_s2[averageNumber], b_s2[averageNumber], c_s2[averageNumber], d_s2[averageNumber], e_s2[averageNumber], f_s2[averageNumber], g_s2[averageNumber];
//    for(int i = 0; i < averageNumber; i ++){
//        as2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3--3.ppm");
//        bs2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3--2.ppm");
//        cs2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3--1.ppm");
//        ds2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3-0.ppm");
//        es2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3-1.ppm");
//        fs2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3-2.ppm");
//        gs2[i].load(filepath + "R2"+ QString::number(i + 1) + "/3-3.ppm");
//        a_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3--3.ppm");
//        b_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3--2.ppm");
//        c_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3--1.ppm");
//        d_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3-0.ppm");
//        e_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3-1.ppm");
//        f_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3-2.ppm");
//        g_s2[i].load(filepath + "R2"+ QString::number(i + 1) + "/-3-3.ppm");
//    }
//    Y3m[0] = imageProcessor.average(as2, averageNumber);
//    Y3m[1] = imageProcessor.average(bs2, averageNumber);
//    Y3m[2] = imageProcessor.average(cs2, averageNumber);
//    Y3m[3] = imageProcessor.average(ds2, averageNumber);
//    Y3m[4] = imageProcessor.average(es2, averageNumber);
//    Y3m[5] = imageProcessor.average(fs2, averageNumber);
//    Y3m[6] = imageProcessor.average(gs2, averageNumber);
//    Y3m_[0] = imageProcessor.average(a_s2, averageNumber);
//    Y3m_[1] = imageProcessor.average(b_s2, averageNumber);
//    Y3m_[2] = imageProcessor.average(c_s2, averageNumber);
//    Y3m_[3] = imageProcessor.average(d_s2, averageNumber);
//    Y3m_[4] = imageProcessor.average(e_s2, averageNumber);
//    Y3m_[5] = imageProcessor.average(f_s2, averageNumber);
//    Y3m_[6] = imageProcessor.average(g_s2, averageNumber);

    n = imageProcessor.normalMap(Y1m, Y1m_, sizeY1m);

    specular = imageProcessor.specular(Y3m, Y3m_, sizeY3m);

    mixed = imageProcessor.albedo_mixed(Y00);

    diff = imageProcessor.albedo_diffuse(mixed, specular);


    rndr = render(diff, n, lights, specular);


   //ADD FOR GRACE CATHEDRAL RENDERING
   // graceCatRdr = RenderGraceCathedral(Y00, Y1m, Y1m_, Y2m, Y2m_);

    n.save(filepath + "n_.ppm");
    specular.save(filepath + "spec.ppm");
    mixed.save(filepath + "mixed.ppm");
    diff.save(filepath + "diff.ppm");
    rndr.save(filepath + "render-"+ QString::number(frame) +".ppm");
   // graceCatRdr.save(filepath + "graceCathedralIllumination.ppm");
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        qDebug() << duration.count() << frame;

    frame++;
    lights[0].position.rotateAroundY(M_PI / 36);

    emit newRender(rndr);
    emit newNormal(n);
    emit newDiffuse(diff);
    emit newSpec(specular);
    emit newMixed(mixed);
}

