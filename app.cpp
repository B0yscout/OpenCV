#include "app.h"



bool app::init(int argc, char* argv[])
{
    try
    {
        // define file and console logger using PLOG library
        static plog::RollingFileAppender<plog::TxtFormatter> fileAppender("OpenCV_Thales.log", 8000, 3); // Create the 1st appender.
        static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender; // Create the 2nd appender.
        plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender); // Initialize the logger with the both appenders.

        PLOGI << "Initialisation du programme";

        // check for 2 args
        if ( argc != 2 )
        {
            printf("usage: my_app_name <Image_Path>\n");
            throw logic_error("Mauvais usage de l'application");
        }

        image = imread( argv[1], IMREAD_COLOR );
        if ( !image.data )
        {
            throw logic_error("No image data \n");
        }

        return true;
    }
    catch(const std::exception& e)
    {
        PLOGF << "Erreur à l'initialisation:" << e.what();
        return false;
    }
    
    
}

void app::run()
{
    PLOGI << "Lancement du programme";
    try
    {
        

        PhotoAnalyser face_detector{};

        face_detector.show_image(image);

        face_detector.show_faces(image);

        // throw logic_error("Application non développée");
    }
    catch(const exception& e)
    {
        PLOGF << "Erreur d'exécution le programme va fermer: " << e.what();
    }
    
    this->exit();
}

void app::clean()
{
    PLOGD << "Clean du programme";
}

void app::exit()
{
    PLOGW << "Sortie  du programme";
}