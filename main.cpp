#include <iostream>

#include "app.h"

int main(int argc, char *argv[])
{

    static plog::RollingFileAppender<plog::CsvFormatter> fileAppender("MultiAppender.csv", 8000, 3); // Create the 1st appender.
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.
    plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); // Initialize the logger with the both appenders.

    app app;
    if(app.init(argc, argv))
    {
        app.run();
    }


    return 0;
}
