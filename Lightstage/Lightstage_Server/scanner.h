#ifndef SCANNER_H
#define SCANNER_H

#include "cameracapture.h"

class Scanner
{
public:
    Scanner();
    int setUp(int maxLevelOfDetail);
    int setUpCal();
    int cleanUp();
    bool scanNextSH();
    bool scanNextCal();
    int getProgess();
    int getCurrentL();
    int getCurrentM();
    int getCurrentI();
    int getCurrentJ();
    
private:
    const int ERROR_OK = 0;
    int iPtr;
    int jPtr;
    int lPtr;
    int mPtr;
    int l;
    CameraCapture capture;
};

#endif // SCANNER_H
