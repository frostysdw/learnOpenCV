#ifndef __QUICK_H__
#define __QUICK_H__

#include <opencv2/opencv.hpp>

using namespace cv;

class QuickDemo{
public:
    void color_Space_Demo(Mat &image);      //图像颜色转换
    void mat_Creation_Demo(Mat &image);     //图像创建赋值 
    void pixel_Visit_Demo(Mat &image);      //图像像素读写
};

#endif