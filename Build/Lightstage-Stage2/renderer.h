#ifndef RENDERER_H
#define RENDERER_H

#include <QImage>
#include <vector>
#include <cmath>
#include <mainwindow.h>
#include <imageprocessor.h>
#include <QObject>
#include <QTimer>


#include <chrono>
using namespace std::chrono;

using namespace std;

struct Vector3D
{
    double x, y, z;

    Vector3D(double xPos = 0, double yPos = 0, double zPos = 0) : x(xPos), y(yPos), z(zPos) {}
    Vector3D normalize()
    {
        float length = sqrt(x*x + y*y + z*z);
        x = x/length;
        y = y/length;
        z = z/length;
        return Vector3D(x, y, z);
    }
    Vector3D rotateAroundX(double theta)
    {
        double y_ = y * cos(theta) - z * sin(theta);
        double z_ = y * sin(theta) + z * cos(theta);
        y = y_;
        z = z_;
        return Vector3D(x, y_, z_);
    }
    Vector3D rotateAroundY(double theta)
    {
        double x_ = x * cos(theta) + z * sin(theta);
        double z_ = -x * sin(theta) + z * cos(theta);
        x = x_;
        z = z_;
        return Vector3D(x_, y, z_);
    }Vector3D rotateAroundZ(double theta)
    {
        double x_ = x * cos(theta) - y * sin(theta);
        double y_ = x * sin(theta) + y * cos(theta);
        x = x_;
        y = y_;
        return Vector3D(x_, y_, z);
    }
    Vector3D add(Vector3D v){
        x += v.x;
        y += v.y;
        z += v.z;
        return Vector3D(x, y, z);
    }
    vector<double> toStdVector(){
        return vector<double> {x, y, z};
    }
    Vector3D fromStdVector(vector<double> v){
        return Vector3D(v[0], v[1], v[2]);
    }
    float length(){
        return sqrt(x * x + y * y + z * z);
    }
};

struct Light
{
    Vector3D position;
    double intensity;
    QColor color;

    Light(Vector3D pos, double i = 1, QColor col = QColor(255, 255, 255)) : position(pos), intensity(i), color(col) {}
};
struct Light_Directional : Light
{

};
struct Light_Point : Light{

};

struct RenderArea{
    double xStart, yStart, xEnd, yEnd;
    RenderArea(double xPos = 0, double yPos = 0, double x2 = 0, double y2 = 0) : xStart(xPos), yStart(yPos), xEnd(x2), yEnd(y2) {}
    void init(double xS, double yS, double xE, double yE){
        xStart = xS;
        yStart = yS;
        xEnd = xE;
        yEnd = yE;
    }
};

class Renderer : public QObject
{
    Q_OBJECT
public:
     explicit Renderer(QObject *parent = nullptr);
public slots:
     void onRender();

private:
    float Ward(float theta_i, float theta_r, float delta, float p_d, float p_s, float alpha);
    ImageProcessor imageProcessor;
    QImage render(QImage &diffuse,  QImage &normals, vector<Light> &lights, QImage &specular);
    vector<Light> lights;
    RenderArea renderArea;
    QImage RenderGraceCathedral(QImage &Y00, QImage Y1m[], QImage Y1m_[], QImage Y2m[], QImage Y2m_[]);

signals:
    void newRender(QImage rndr);
    void newNormal(QImage normal);
    void newDiffuse(QImage diff);
    void newSpec(QImage spec);
    void newMixed(QImage mixed);
};

#endif // RENDERER_H
