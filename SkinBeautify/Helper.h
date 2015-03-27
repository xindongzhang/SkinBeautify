#ifndef HELPER_H
#define HELPER_H

#include "common.h"

class Helper
{
public:
	static void DisplayTogether(const cv::Mat& left,
		                        const cv::Mat& right);
	static void SaveDisplayTogether(const std::string filename,
		                            const cv::Mat& left,
		                            const cv::Mat& right);
};

#endif
