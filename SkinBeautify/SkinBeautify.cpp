#include "SkinBeautify.h"

bool SkinBeautify::Init(const cv::Mat& Origin_Img0)
{
	// handling error
	if ( Origin_Img0.empty() ){
		std::cout<< "input img is empty"<< std::endl;
		assert(Origin_Img0.empty());
		return false;
	} else{
		this->Origin_Img = Origin_Img0.clone();
		return true;
	}
}

void SkinBeautify::SkinSmooth(const cv::Mat& src,
	                                cv::Mat& dst)
{
	int CHANELS = src.channels();
	//handling error
	if ( src.empty() )
	{
		std::cout<< "input img is empty"<< std::endl;
		assert(src.empty());
	} 
	/*--------------*/
	int Neighbor = 3;
	cv::Mat MeanColor;
	cv::Mat SigmaColor;
	double SigmaSpace = 3;
	if (CHANELS == 1){
		/*----------------------------------------*/
		cv::meanStdDev(src, MeanColor, SigmaColor);
		cv::bilateralFilter(src, dst, Neighbor, 
			                SigmaColor.at<double>(0,0), 
			                SigmaSpace);
		/*----------------------------------------*/
	} else {
		/*----------------------------------------*/
		cv::Mat srcLAB;
		std::vector<cv::Mat> LAB;
		std::vector<cv::Mat> LAB_Merge;
		cv::cvtColor(src, srcLAB, cv::COLOR_BGR2Lab);
		cv::split(srcLAB, LAB);
		for (size_t i = 0; i < LAB.size(); ++i)
		{
			cv::Mat tmp;
			cv::meanStdDev(LAB[i], MeanColor, SigmaColor);
			cv::bilateralFilter(LAB[i], tmp, Neighbor, 
				                SigmaColor.at<double>(0,0), 
				                SigmaSpace);
			LAB_Merge.push_back(tmp);
		}
		cv::merge(LAB_Merge, dst);
		cv::cvtColor(dst, dst, cv::COLOR_Lab2BGR);
		/*----------------------------------------*/
	}

}

cv::Mat SkinBeautify::Get_Origin_Img()
{
	// handling error
	if (this->Origin_Img.empty())
	{
		std::cout<< "origin image is empty, init first"<< std::endl;
		assert(this->Origin_Img.empty());
	}
	/*---------------*/
	return this->Origin_Img;
}

cv::Mat SkinBeautify::Get_Beautified_Img()
{
	// handling error
	if (this->Beautified_Img.empty()){
		this->SkinSmooth(this->Origin_Img, this->Beautified_Img);
		return Beautified_Img;
	} else {
		return Beautified_Img;
	}
}