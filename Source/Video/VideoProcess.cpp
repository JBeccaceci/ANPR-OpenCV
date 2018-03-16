//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include "VideoProcess.h"
#include "../General/Utility.hpp"
#include "../Console/Console.h"

using namespace std;
using namespace cv;

//////////////////////////////////////////////////////////////
/// Constructor class
//////////////////////////////////////////////////////////////
VideoProcess::VideoProcess(ConfigManagement * nConfig)
{

	Config       = nConfig;
	inputWidth   = atoi(Config->GetConfigValue(VIDEO_INPUT_WIDTH).c_str());
	inputHeight  = atoi(Config->GetConfigValue(VIDEO_INPUT_HEIGHT).c_str());
	videoDevice  = atoi(Config->GetConfigValue(DETECTOR_STRING_VAL).c_str());
	stateProcess = true;

}

//////////////////////////////////////////////////////////////
/// Destructor class
//////////////////////////////////////////////////////////////
VideoProcess::~VideoProcess()
{

	stateProcess = false;

}

//////////////////////////////////////////////////////////////
/// Initialize video capture
//////////////////////////////////////////////////////////////
void VideoProcess::InitializeCapture()
{
    //  Create window
    cv::namedWindow("MainWindow", 1);
    //cv::namedWindow("WindowArea", 1);
    cv::namedWindow("WindowRECT", 1);
}

//////////////////////////////////////////////////////////////
/// Area of interest
//////////////////////////////////////////////////////////////
cv::Rect VideoProcess::ComputeArea()
{
	//	Area of interest
	areaX      = atoi(Config->GetConfigValue(VIDEO_AREA_X).c_str());
	areaY      = atoi(Config->GetConfigValue(VIDEO_AREA_Y).c_str());
	areaWidth  = atoi(Config->GetConfigValue(VIDEO_AREA_WIDTH).c_str());
	areaHeight = atoi(Config->GetConfigValue(VIDEO_AREA_HEIGHT).c_str());

	//	Check width size
	if (areaWidth > inputWidth)
		areaWidth = inputWidth;

	//	Check height size
	if (areaHeight > inputHeight)
		areaHeight = inputHeight;

	//	Create area
	cv::Rect rArea(areaX, areaY, areaWidth, areaHeight);

	return rArea;
}

//////////////////////////////////////////////////////////////
/// Process video frame
//////////////////////////////////////////////////////////////
void VideoProcess::MainProcess()
{
	cv::Mat vFrame;
	cv::Mat vFrameArea;
	std::vector<cv::Rect> areaRECT;

	//	Initialize video
	VideoCapture Video(videoDevice);
    if (!Video.isOpened())
    {
        std::cout << "ANPR --> VideoProcess: Error load." << "\n";
        return;
    }

    //	Area of interest
    cv::Rect Area = ComputeArea();

    //	Init video class
    PlateDetection * Detector = newDetector(Config);
    
    //	Loop
	while (stateProcess)
	{
		//	Read frame
		Video.read(vFrame);

		//	Frame area
		vFrameArea = vFrame(Area);
        
		//	Detect plate
        areaRECT = Detector->DetectPlateFromArea(vFrame, Area);
        
        //	Render area
        cv::rectangle(vFrame, Area, cv::Scalar(0, 0, 255), 1, 8, 0);

        //  Draw rectangles
        RenderRECTs(vFrame, areaRECT);
        
        //  Show frames
        cv::imshow("MainWindow", vFrame);
        //cv::imshow("WindowArea", vFrameArea);
        
        //  Wait it!
        if (ProcessKey(cv::waitKey(1)) == KEY_EXIT)
        {
        	break;
        }
	}

	//	Exit message
	std::cout << "ANPR --> Application exit" << "\n";

	//	Delete
	delete Config;
}
