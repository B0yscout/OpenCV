#include <gtest/gtest.h>
#include "detect.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;

TEST(temp, dummy)
{
    Mat image;
    image = imread( "ressources/friends.jpg", IMREAD_COLOR );

    
    EXPECT_EQ(1, 1);
}
