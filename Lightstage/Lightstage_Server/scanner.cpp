//=============================================================================
// The scanner is responsible for checking if all necassary spherical harmonic
// files are available and adding missing files. It also manages the capture
// process by computing the order and degree of the next SH to be used for
// the next scan.
//=============================================================================

#include "scanner.h"
#include <QDebug>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <sphericalharmonics.h>

Scanner::Scanner()
{
    capture.printInfo();
}

int Scanner::setUp(int maxLevelOfDetail)
{
    SphericalHarmonics::createGraceCathedralSphericalHarmonics();
    //check for all needed files
    for(int l = 0; l <= maxLevelOfDetail; l++){
        for(int m = -l; m <= l; m++){
            bool missingFile = true;
            for(int x = 1; x <= 6; x++){
                struct stat buffer;
                std::string file = "/home/bretznic/Documents/Lightstage/SphericalHarmonics/SPH-"+ std::to_string(l) + "-" + std::to_string(m) + "-"+ std::to_string(x) + ".bmp";
                std::string file_inv = "/home/bretznic/Documents/Lightstage/SphericalHarmonics/SPH--"+ std::to_string(l) + "-" + std::to_string(m) + "-"+ std::to_string(x) + ".bmp";
                bool fileReady = stat(file.c_str(), &buffer) == 0 || stat(file_inv.c_str(), &buffer) == 0;
                missingFile = missingFile || !fileReady;
            }
            qDebug()<< missingFile;
            if(missingFile)
                SphericalHarmonics::createSphericalHarmonics(l, m);
            qDebug() << "l:" << l << "m:" << m;
        }
    }

    int error = capture.SetUp();
    if(error != ERROR_OK){
        qDebug() << "Camera setup failed!";
    }
    l = maxLevelOfDetail;
    lPtr = 0;
    mPtr = 0;
    return 0;
}

int Scanner::cleanUp()
{
    capture.CleanUp();
}

bool Scanner::scanNextSH()
{
    qDebug() << lPtr << mPtr;
    int error = capture.CaptureCamera(lPtr, mPtr);
    if(error != ERROR_OK){
        qDebug() << "Camera capturing failed!";
    }
    if(-lPtr == l && mPtr == l){
        return true;
    }

    if(lPtr > 0){
        lPtr = -lPtr;
        return false;
    }
    else if(lPtr < 0){
        lPtr = -lPtr;
    }


    if(mPtr == lPtr){
        lPtr++;
        mPtr = -lPtr;
    }
    else mPtr++;

    return false;
}

int Scanner::getProgess()
{
    int jobs = 2 * l + 1;
    return ((float)jobs / (float)(mPtr + (2 * (lPtr-1) + 1))) * 100;
}

int Scanner::getCurrentL(){    return lPtr;    }

int Scanner::getCurrentM(){    return mPtr;    }
