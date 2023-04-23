#pragma once

// includes pour la librairie de logging
#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/CsvFormatter.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

// includes pour la librairie opencv
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


using namespace std;
using namespace cv;


class app
{
    public:
        app(){}
        ~app(){this->clean();}
        bool init(int argc, char* argv[]);
        void run();
    private:
        void clean();
        void exit();
};