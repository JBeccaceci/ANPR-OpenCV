//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include "PlateDetection.h"
#include "../General/Utility.hpp"

//////////////////////////////////////////////////////////////
/// Constructor class
//////////////////////////////////////////////////////////////
PlateDetection::PlateDetection(ConfigManagement * Config)
{

}

//////////////////////////////////////////////////////////////
/// Destructor class
//////////////////////////////////////////////////////////////
PlateDetection::~PlateDetection()
{

}

///////////////////////////////////////////////////////////
/// Detect plate from a region
///////////////////////////////////////////////////////////
std::vector<cv::Rect> PlateDetection::DetectPlate(cv::Mat iFrame, std::vector<cv::Rect> pRegions)
{
	cv::Mat fGray;

	//	Convert to gray colors
	cv::cvtColor(iFrame, fGray, CV_BGR2GRAY);

	//	Regions
    std::vector<cv::Rect> dRegions;
	for (int i = 0; i < pRegions.size(); ++i)
	{
		//	Copy rect
		cv::Rect rRegion = pRegions[i];

		//	Check plate size
		if ((rRegion.width < MIN_PLATE_WIDTH_PX) || 
		    (rRegion.height < MIN_PLATE_HEIGHT_PX))
		        continue;

		//	Cropped frame
		cv::Mat iCropped = fGray(rRegion);

		//	Frame data
		int Width       = iCropped.size().width;
		int Height      = iCropped.size().height;
		int offsetX     = rRegion.x;
		int offsetY     = rRegion.y;
		float scale     = 1.0; // Change to correct scale

		//	Calculate max width/height
		float maxWidth  = ((float) Width) * (DETECT_PERCENT_WIDTH / 100.0f) * scale;
      	float maxHeight = ((float) Height) * (DETECT_PERCENT_HEIGHT / 100.0f) * scale;

      	//	Create sizes
      	cv::Size minPlateSize(MIN_PLATE_WIDTH_PX, MIN_PLATE_HEIGHT_PX);
      	cv::Size maxPlateSize(maxWidth, maxHeight);

      	//	Find plates regions
      	std::vector<cv::Rect> Regions = findRegion(iCropped, minPlateSize, maxPlateSize);

      	//	Process regions
      	for(int i = 0; i < Regions.size(); i++)
	    {
	        Regions[i].x      = (Regions[i].x / scale);
	        Regions[i].y      = (Regions[i].y / scale);
	        Regions[i].width  = Regions[i].width / scale;
	        Regions[i].height = Regions[i].height / scale;

	        // Expand the retangle to correct dimensions
	        Regions[i] = expandRect(Regions[i], 0, 0, Width, Height);

	        Regions[i].x = Regions[i].x + offsetX;
	        Regions[i].y = Regions[i].y + offsetY;
	    }
        
        //  Copy regions
        for (unsigned int j = 0; j < Regions.size(); j++)
            dRegions.push_back(Regions[j]);
	}

	return dRegions;
}

//////////////////////////////////////////////////////////////
/// Detect plate from a region
//////////////////////////////////////////////////////////////
std::vector<cv::Rect> PlateDetection::DetectPlateFromFrame(cv::Mat iFrame)
{

	//	Add only region
    std::vector<cv::Rect> pRegions;
    pRegions.push_back(cv::Rect(0, 0, iFrame.cols, iFrame.rows));

    //	Detect!
    return DetectPlate(iFrame, pRegions);
}

///////////////////////////////////////////////////////////
/// Detect plate from a area
///////////////////////////////////////////////////////////
std::vector<cv::Rect> PlateDetection::DetectPlateFromArea(cv::Mat iFrame, cv::Rect areaRECT)
{
	//	Add only region
    std::vector<cv::Rect> pRegions;
    pRegions.push_back(areaRECT);

	//	Detect!
    return DetectPlate(iFrame, pRegions);
}
