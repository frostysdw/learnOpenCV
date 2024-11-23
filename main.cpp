#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp> 
#include <iostream> 
#include "h/quick.h"

using namespace std;
using namespace cv;  //opencv的命名空间

int main(int, char**){
    Mat img; //保存图像的类
    img = imread("../photo/avatar.png");
    /*灰度图, 其他类似
    Mat grayimg;
    grayimg = imread("../avatar.png", IMREAD_GRAYSCALE);
    */
   // namedWindow("输入窗口", WINDOW_FREERATIO);
    if (img.empty()) {
        cout << "确定图片位置" << endl;
        return -1;
    }
   // imshow("输入窗口", img);

    QuickDemo qd;
    //qd.colorSpace_Demo(img);
    qd.matCreation_Demo(img);

    waitKey(0); //阻塞窗口 0 一直显示
    destroyAllWindows(); //销毁所有窗口
    return 0;
}
