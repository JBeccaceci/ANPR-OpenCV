#ifndef VIDEO_PROCESS_H
#define VIDEO_PROCESS_H

//////////////////////////////////////////////////////////////
/// Includes
//////////////////////////////////////////////////////////////
#include "../Detector/DetectorFactory.h"

//////////////////////////////////////////////////////////////
/// Def
//////////////////////////////////////////////////////////////
#define VIDEO_DEVICE_VAL   "CAMERA_DEVICE_NUMBER"
#define VIDEO_INPUT_WIDTH  "INPUT_WIDTH"
#define VIDEO_INPUT_HEIGHT "INPUT_HEIGHT"
#define VIDEO_AREA_X       "REGION_DETECTION_X"
#define VIDEO_AREA_Y       "REGION_DETECTION_Y"
#define VIDEO_AREA_WIDTH   "REGION_DETECTION_WIDTH"
#define VIDEO_AREA_HEIGHT  "REGION_DETECTION_HEIGHT"

class VideoProcess
{
	public:
		//////////////////////////////////////////////////////////////
    	/// Constructor class
    	//////////////////////////////////////////////////////////////
		VideoProcess(ConfigManagement * nConfig);

		//////////////////////////////////////////////////////////////
	    /// Destructor class
	    //////////////////////////////////////////////////////////////
	    ~VideoProcess();

		//////////////////////////////////////////////////////////////
	    /// Process video frame
	    //////////////////////////////////////////////////////////////
	    void MainProcess();

		//////////////////////////////////////////////////////////////
	    /// Process state
	    //////////////////////////////////////////////////////////////
	    bool stateProcess;

		//////////////////////////////////////////////////////////////
	    /// Initialize video capture
	    //////////////////////////////////////////////////////////////
	    void InitializeCapture();

	private:
		//////////////////////////////////////////////////////////////
	    /// Config pointer
	    //////////////////////////////////////////////////////////////
		ConfigManagement * Config;

		//////////////////////////////////////////////////////////////
	    /// Plate class
	    //////////////////////////////////////////////////////////////
		PlateDetection * Plate;

		//////////////////////////////////////////////////////////////
	    /// Area of interest
	    //////////////////////////////////////////////////////////////
		cv::Rect ComputeArea();

		//////////////////////////////////////////////////////////////
	    /// Resolution camera
	    //////////////////////////////////////////////////////////////
		int inputWidth;
		int inputHeight;

		//////////////////////////////////////////////////////////////
	    /// Video device
	    //////////////////////////////////////////////////////////////
	    int videoDevice;

		//////////////////////////////////////////////////////////////
	    /// Area of interest X and Y
	    //////////////////////////////////////////////////////////////
	    int areaX;
	    int areaY;

	    //////////////////////////////////////////////////////////////
	    /// Area of interest width and height
	    //////////////////////////////////////////////////////////////
	    int areaWidth;
	    int areaHeight;
};

#endif
