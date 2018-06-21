#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace cv;
using namespace Eigen;

int main( int argc, char** argv )
{
    MatrixXd result;
    Mat image;
    image = imread("/home/zf/Pictures/test.jpg", CV_LOAD_IMAGE_COLOR );
    namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    imshow( "Display Image", image );
    waitKey(0);
    destroyWindow("Display Image");
    return 0;

}