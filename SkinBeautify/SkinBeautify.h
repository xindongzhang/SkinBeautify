#ifndef SKINBEAUTIFY_H
#define SKINBEAUTIFY_H
#include "common.h"
class SkinBeautify
{
private:
	cv::Mat Origin_Img;
	cv::Mat Beautified_Img;
public:
	cv::Mat Get_Origin_Img();
	cv::Mat Get_Beautified_Img();
	bool Init(const cv::Mat& Origin_Img0);
	void SkinSmooth(const cv::Mat& src,
		                  cv::Mat& dst);
};

#endif