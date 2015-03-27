#include "Helper.h"

void Helper::DisplayTogether(const cv::Mat& left,
	                         const cv::Mat& right)
{
	// handling error
	if (left.empty() || left.empty())
	{
		std::cout<< "left or right is empty"<< std::endl;
		assert(left.empty() || left.empty());
	}
	// display together
	cv::Mat Display;
	const std::string WindowsName = "DisplayTogether";
	cv::hconcat(left, right, Display);
	cv::imshow(WindowsName, Display);
	cv::waitKey();
	cv::destroyWindow(WindowsName);
}

void Helper::SaveDisplayTogether(const std::string filename,
	                             const cv::Mat& left,
	                             const cv::Mat& right)
{
	// handling error
	if (left.empty() || left.empty())
	{
		std::cout<< "left or right is empty"<< std::endl;
		assert(left.empty() || left.empty());
	}
	// display together
	cv::Mat Display;
	cv::hconcat(left, right, Display);
	cv::imwrite(filename, Display);
}