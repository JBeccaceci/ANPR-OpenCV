//
//  Utility.cpp
//  OpenCV-PlateRecognition
//
//  Created by Juan Beccaceci on 2/8/17.
//  Copyright © 2017 Juan Beccaceci. All rights reserved.
//
#include "Utility.hpp"

//////////////////////////////////////////////////////////////
/// Render vector of rects
//////////////////////////////////////////////////////////////
void RenderRECTs(cv::Mat rMat, std::vector<cv::Rect> areaRECT)
{
    cv::Mat vFrameArea;

    //  Draw rectangles
    for(size_t  i = 0; i < areaRECT.size(); i++)
    {
        rectangle(rMat, areaRECT[i].tl(), areaRECT[i].br(), cv::Scalar(0, 0, 255), 1, 8, 0);
        vFrameArea = rMat(areaRECT[i]);
        cv::imshow("WindowRECT", vFrameArea);
    }
}

//////////////////////////////////////////////////////////////
/// Expand rectangle
//////////////////////////////////////////////////////////////
cv::Rect expandRect(cv::Rect original, int expandXPixels, int expandYPixels, int maxX, int maxY)
{
    cv::Rect expandedRegion = original;
    
    float halfX           = round((float) expandXPixels / 2.0);
    float halfY           = round((float) expandYPixels / 2.0);
    
    expandedRegion.x      = expandedRegion.x - halfX;
    expandedRegion.width  = expandedRegion.width + expandXPixels;
    expandedRegion.y      = expandedRegion.y - halfY;
    expandedRegion.height = expandedRegion.height + expandYPixels;
    
    expandedRegion.x      = std::min(std::max(expandedRegion.x, 0), maxX);
    expandedRegion.y      = std::min(std::max(expandedRegion.y, 0), maxY);
    
    if (expandedRegion.x + expandedRegion.width > maxX)
        expandedRegion.width = maxX - expandedRegion.x;
    
    if (expandedRegion.y + expandedRegion.height > maxY)
        expandedRegion.height = maxY - expandedRegion.y;
    
    return expandedRegion;
}
