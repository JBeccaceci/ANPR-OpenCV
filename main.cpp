#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "Source/Config/ConfigManagement.h"
#include "Source/Video/VideoProcess.h"

int main(int argc, char** argv)
{
    //  Version
    std::cout << "ANPR --> OpenCV Version: " << CV_VERSION << "\n";
    
    //	Init config
    ConfigManagement * Config = new ConfigManagement();
    if (!Config->fileFound)
    {
        return 0;
    }
    
    //  Video process initialize
    VideoProcess Video(Config);
    
    //  Initialize capture
    Video.InitializeCapture();
    
    //  Main video
    Video.MainProcess();
    
    return 0;
}
