#ifndef PLATE_DETECTION_H
#define PLATE_DETECTION_H

//////////////////////////////////////////////////////////////
/// Includes
//////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#include "../Config/ConfigManagement.h"

//////////////////////////////////////////////////////////////
/// Min plate size in pixels
//////////////////////////////////////////////////////////////
#define MIN_PLATE_WIDTH_PX        70
#define MIN_PLATE_HEIGHT_PX       35

//////////////////////////////////////////////////////////////
/// Detection input size
//////////////////////////////////////////////////////////////
#define DETECTION_INPUT_WIDTH     1280
#define DETECTION_INPUT_HEIGHT    720

//////////////////////////////////////////////////////////////
/// Percents values of detections
//////////////////////////////////////////////////////////////
#define DETECT_PERCENT_WIDTH       100
#define DETECT_PERCENT_HEIGHT      100

class PlateDetection
{

	public:
		//////////////////////////////////////////////////////////////
    	/// Constructor class
    	//////////////////////////////////////////////////////////////
		PlateDetection(ConfigManagement * Config);

		//////////////////////////////////////////////////////////////
	    /// Destructor class
	    //////////////////////////////////////////////////////////////
	    virtual ~PlateDetection();

        //////////////////////////////////////////////////////////////
        /// Detect plate from a region
        //////////////////////////////////////////////////////////////
        std::vector<cv::Rect> DetectPlateFromFrame(cv::Mat iFrame);

        ///////////////////////////////////////////////////////////
        /// Detect plate from a area
        ///////////////////////////////////////////////////////////
        std::vector<cv::Rect> DetectPlateFromArea(cv::Mat iFrame, cv::Rect areaRECT);

        //////////////////////////////////////////////////////////////
        /// Find plate
        //////////////////////////////////////////////////////////////
        virtual std::vector<cv::Rect> findRegion(cv::Mat iFrame, cv::Size minSize, cv::Size maxSize) = 0;
        
	private:

        //////////////////////////////////////////////////////////////
        /// Detect plate from a region
        //////////////////////////////////////////////////////////////
        std::vector<cv::Rect> DetectPlate(cv::Mat iFrame, std::vector<cv::Rect> pRegions);

};

#endif ///< PLATE_DETECTION_H
