#include "../h/quick.h"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/types.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void QuickDemo::colorSpace_Demo(Mat &image){
    Mat gray, hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("HSV", hsv);
    imshow("灰度", gray);
    // imwrite("../photo/hsv.png", hsv); //保存图片
    // imwrite("../photo/gray.png", gray);
}

void QuickDemo::matCreation_Demo(Mat &image){
    Mat m1, m2;
    m1 = image.clone();     //克隆  
    image.copyTo(m2);    //拷贝

    /*创建空白图像*/
    Mat m3 = Mat::zeros(Size(512,512), CV_8UC3);
    m3 = Scalar(255,0,0);
    cout << "width:" << m3.cols << " height:" << m3.rows << endl;
    cout << "channels:" << m3.channels() << endl;
    // cout << m3 << endl; 
    // imshow("图像3", m3);
    Mat m4 = m3; //m3和m4一样，修改等于同时修改两个，若要独立需用m1/m2
    m4 = Scalar(255,255,0);
    // imshow("图像4", m4);
    /*使用目标图像模版创建*/
    Mat m5 = Mat::zeros(image.size(), image.type()); 
}