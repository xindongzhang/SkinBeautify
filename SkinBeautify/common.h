#ifndef COMMON_H
#define COMMON_H

#pragma warning(disable : 4995)
#pragma warning(disable : 4996)

#include <opencv2/opencv.hpp>
#include <iostream>

#define CV_VER CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)
#ifdef _DEBUG
#define MY_LIB(name) name "d"
#define CV_LIB(name) "opencv_" name CV_VER "d"
#else
#define MY_LIB(name) name
#define CV_LIB(name) "opencv_" name CV_VER
#endif

// opencv
#pragma comment(lib, CV_LIB("calib3d"))
#pragma comment(lib, CV_LIB("contrib"))
#pragma comment(lib, CV_LIB("core"))
#pragma comment(lib, CV_LIB("features2d"))
#pragma comment(lib, CV_LIB("flann"))
#pragma comment(lib, CV_LIB("gpu"))
#pragma comment(lib, CV_LIB("highgui"))
#pragma comment(lib, CV_LIB("imgproc"))
#pragma comment(lib, CV_LIB("legacy"))
#pragma comment(lib, CV_LIB("ml"))
#pragma comment(lib, CV_LIB("objdetect"))
#pragma comment(lib, CV_LIB("ts"))
#pragma comment(lib, CV_LIB("video"))


#endif // LAMP_LIBCFG_H