//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include "GPUDetection.h"

//////////////////////////////////////////////////////////////
/// Constructor class
//////////////////////////////////////////////////////////////
GPUDetection::GPUDetection(ConfigManagement * Config) : PlateDetection(Config)
{

	cCascade = cv::cuda::CascadeClassifier::create(Config->GetConfigValue(HARD_CASCADE_DIR));
	
	/*
	if (!cCascade.load(Config->GetConfigValue(HARD_CASCADE_DIR)))
	{

		std::cout << "ANPR --> Error al cargar el archivo classifier GPU \n";

	}
	*/

}

//////////////////////////////////////////////////////////////
/// Destructor class
//////////////////////////////////////////////////////////////
GPUDetection::~GPUDetection()
{
	
}

//////////////////////////////////////////////////////////////
/// Find plate 
//////////////////////////////////////////////////////////////
std::vector<cv::Rect> GPUDetection::findRegion(cv::Mat iFrame, cv::Size minSize, cv::Size maxSize)
{
	std::vector<cv::Rect> plateResult;
	cv::cuda::GpuMat gFrame;
	cv::cuda::GpuMat grayFrame;
	cv::cuda::GpuMat gBuffer;

	//	Upload frame
	gFrame.upload(iFrame);

	//	Gray scale
	cv::cuda::cvtColor(gFrame, grayFrame, cv::COLOR_BGR2GRAY);

	//	Cascade GPU data
	cCascade->setFindLargestObject(false);
    cCascade->setScaleFactor(1.1);
    cCascade->setMinNeighbors(3);

    //	Detect 
    cCascade->detectMultiScale(grayFrame, gBuffer);
    cCascade->convert(gBuffer, plateResult);

    std::cout << "Cacs";
    
	return plateResult;
}








