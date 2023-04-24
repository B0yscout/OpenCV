// includes pour la librairie opencv
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

class PhotoAnalyser{
    private:

    public:
        void show_image(Mat image);
        void show_faces(Mat image);
};