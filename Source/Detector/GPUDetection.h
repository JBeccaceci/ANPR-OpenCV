#ifndef GPU_DETECTION_H
#define GPU_DETECTION_H

//////////////////////////////////////////////////////////////
/// Includes
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <vector>

#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudawarping.hpp>

#include "../Config/ConfigManagement.h"
#include "PlateDetection.h"

//////////////////////////////////////////////////////////////
/// Defines
//////////////////////////////////////////////////////////////
#define HARD_CASCADE_DIR "CASCADE_DIRECTORY"

class GPUDetection : public PlateDetection
{

	public:

		//////////////////////////////////////////////////////////////
    	/// Constructor class
    	//////////////////////////////////////////////////////////////
		GPUDetection(ConfigManagement * Config);

		//////////////////////////////////////////////////////////////
	    /// Destructor class
	    //////////////////////////////////////////////////////////////
	    virtual ~GPUDetection();

		//////////////////////////////////////////////////////////////
	    /// Find plate 
	    //////////////////////////////////////////////////////////////
	    std::vector<cv::Rect> findRegion(cv::Mat iFrame, cv::Size minSize, cv::Size maxSize);

	private:

		//////////////////////////////////////////////////////////////
	    /// Cascade
	    //////////////////////////////////////////////////////////////
        cv::Ptr<cv::cuda::CascadeClassifier> cCascade;
};

#endif ///< GPU_DETECTION_H