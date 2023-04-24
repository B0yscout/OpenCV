#pragma once

#include <detect.h>

// includes pour la librairie de logging
//#include <plog/Formatters/CsvFormatter.h>
#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>

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
        Mat image;
};