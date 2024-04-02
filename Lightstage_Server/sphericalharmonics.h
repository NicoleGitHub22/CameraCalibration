#ifndef SPHERICALHARMONICS_H
#define SPHERICALHARMONICS_H

#include <vector>
#include <QImage>
#include <math.h>

using namespace std;

struct Vector3D
{
    double x, y, z;

    Vector3D(double xPos = 0, double yPos = 0, double zPos = 0) : x(xPos), y(yPos), z(zPos) {}
    void normalize()
    {
        float length = sqrt(x*x + y*y + z*z);
        x = x/length;
        y = y/length;
        z = z/length;
    }
};

struct Direction
{
    double theta, phi;
    Direction(double t, double p) : theta(t), phi(p) {}
};

class SphericalHarmonics
{
public:
    static void createSphericalHarmonics(int l, int m);
    static void createGraceCathedralSphericalHarmonics();

private:
    static Direction getAnglesFromPoint(Vector3D &point);
    static vector<double> Y(int l, int m, vector<Vector3D> &points);
    static void normalizeValues(vector<vector<double> > &v);
    static int factorial(int x);
    static float normBrightness(float x, float y, float alpha);
};
#endif // SPHERICALHARMONICS_H
