#ifndef SCANNER_H
#define SCANNER_H

#include "cameracapture.h"

class Scanner
{
public:
    Scanner();
    int setUp(int maxLevelOfDetail);
    int cleanUp();
    bool scanNextSH();
    int getProgess();
    int getCurrentL();
    int getCurrentM();
private:
    const int ERROR_OK = 0;
    int lPtr;
    int mPtr;
    int l;
    CameraCapture capture;
};

#endif // SCANNER_H
