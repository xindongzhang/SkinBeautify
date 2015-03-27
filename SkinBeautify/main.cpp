#include "common.h"
#include "SkinBeautify.h"
#include "config.h"
#include "Helper.h"

int main(void)
{
	std::string InDir  = "./data/";
	std::string OutDir = "result_";
	std::string filename = "test2.jpg";
	std::string inputname = InDir + filename;
	std::string resultname = OutDir + filename;
	cv::Mat img = cv::imread(inputname, LOAD_IMAGE_COLOR);
	// doing smooth twice
	SkinBeautify SB;
	SkinBeautify SB1;
	SB.Init(img);
	SB1.Init(SB.Get_Beautified_Img());
	Helper::DisplayTogether(img, SB1.Get_Beautified_Img());
	Helper::SaveDisplayTogether(resultname, img, SB1.Get_Beautified_Img());
	return 0;
}