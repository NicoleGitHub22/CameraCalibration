#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include "cameracapture.h"
#include "stdafx.h"
#include <FlyCapture2.h>

#include <iostream>
#include <sstream>
using namespace FlyCapture2;
class CameraCapture
{
public:
    int printInfo();
    int SetUp();
    int CaptureCamera(int l, int m);
    int CleanUp();
private:
    void PrintBuildInfo();
    void PrintCameraInfo(CameraInfo *pCamInfo);
    void PrintError(Error error);
    int RunSingleCamera(PGRGuid guid);
    int SetUpCamera(PGRGuid guid);
};

#endif // CAMERACAPTURE_H
