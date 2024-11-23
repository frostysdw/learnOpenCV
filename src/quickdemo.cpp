#include "../h/quick.h"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/core/types.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void QuickDemo::color_Space_Demo(Mat &image){
    Mat gray, hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("HSV", hsv);
    imshow("灰度", gray);
    // imwrite("../photo/hsv.png", hsv); //保存图片
    // imwrite("../photo/gray.png", gray);
}

void QuickDemo::mat_Creation_Demo(Mat &image){
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

void QuickDemo::pixel_Visit_Demo(Mat &image){
    int w, h, dims;
    w = image.cols;
    h = image.rows;
    dims = image.channels();
    for(int row = 0; row < h; row++){
        for (int col = 0; col < w; col++) {
            if (dims == 1) { // 灰度图
                int pv = image.at<uchar>(row, col);
                image.at<uchar>(row,col) = 255 - pv;
            }
            if (dims == 3) { // 彩色图
                Vec3b bgr = image.at<Vec3b>(row, col);
                image.at<Vec3b>(row,col)[0] = 255 - bgr[0];
                image.at<Vec3b>(row,col)[1] = 255 - bgr[1];
                image.at<Vec3b>(row,col)[2] = 255 - bgr[2]; 
            }
        }
    }
    /* for(int row = 0; row < h; row++){
        uchar* current_row = image.ptr<uchar>(row);
        for (int col = 0; col < w; col++) {
            if (dims == 1) { // 灰度图
                int pv = *current_row;
                *current_row = 255 - pv;
            }
            if (dims == 3) { // 彩色图
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
                *current_row++ = 255 - *current_row;
            }
        }
    } */
    imshow("像素读写演示", image);
}
