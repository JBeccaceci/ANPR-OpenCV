#ifndef DETECTOR_FACTORY_H
#define DETECTOR_FACTORY_H

//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include <opencv2/opencv.hpp>
#include "../Config/ConfigManagement.h"
#include "GPUDetection.h"
#include "CPUDetection.h"
#include "OPENCLDetection.h"
#include "PlateDetection.h"

//////////////////////////////////////////////////////////////
/// Defines
//////////////////////////////////////////////////////////////
#define DETECTOR_STRING_VAL        "DETECTOR_TYPE"

//////////////////////////////////////////////////////////////
/// Type detections
//////////////////////////////////////////////////////////////
#define FIND_CONTOURNS_TYPE_GPU    "GPU"
#define FIND_CONTOURNS_TYPE_CPU    "CPU"
#define FIND_CONTOURNS_TYPE_OPENCL "OPENCL"

//////////////////////////////////////////////////////////////
/// Get detector
//////////////////////////////////////////////////////////////
PlateDetection * newDetector(ConfigManagement * Config);


#endif
