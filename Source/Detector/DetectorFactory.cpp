//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include "DetectorFactory.h"

//////////////////////////////////////////////////////////////
/// Get detector
//////////////////////////////////////////////////////////////
PlateDetection * newDetector(ConfigManagement * Config)
{
	if (Config->GetConfigValue(DETECTOR_STRING_VAL) == FIND_CONTOURNS_TYPE_GPU)
	{

		return new GPUDetection(Config);

	}
	else if (Config->GetConfigValue(DETECTOR_STRING_VAL) == FIND_CONTOURNS_TYPE_CPU)
	{

        return new CPUDetection(Config);

	}
	else if (Config->GetConfigValue(DETECTOR_STRING_VAL) == FIND_CONTOURNS_TYPE_OPENCL)
	{

		return new OPENCLDetection(Config);

	}
    
    return new CPUDetection(Config);
}
