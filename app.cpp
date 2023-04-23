#include "app.h"

bool app::init(int argc, char* argv[])
{
    try
    {
        PLOGI << "Initialisation du programme";

        // check for 2 args
        if ( argc != 2 )
        {
            throw logic_error("Mauvais usage de l'application");
            printf("usage: my_app_name <Image_Path>\n");
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
        /*
        Mat image = imread( argv[1], IMREAD_COLOR );
        if ( !image.data )
        {
            printf("No image data \n");
            return false;
        }

        cout << "display image" << endl;

        namedWindow("Display Image", WINDOW_AUTOSIZE );
        imshow("Display Image", image);
        waitKey(0);
        
        // PreDefined trained XML classifiers with facial features
        CascadeClassifier faceDetector;
    
        // Load classifiers from "opencv/data/haarcascades" directory
        // nestedCascade.load( "/usr/local/share/opencv4/haarcascades/haarcascade_eye_tree_eyeglasses.xml" ) ;
        faceDetector.load( "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_default.xml" ) ;


        namedWindow("Face Detection");//Declaring a window to show the result//
        vector<Rect>faces;//Declaring a rectangular vector named faces//
        vector<Rect>boundary;//Declaring a rectangular vector named rectangle//
        faceDetector.detectMultiScale(image, faces, 1.1, 4, CASCADE_SCALE_IMAGE, Size(20, 20));//Detecting the faces in 'image_with_humanfaces' matrix//
        
        cout << faces.size() << " faces detedected." << endl;
        
        for (size_t i = 0; i < faces.size(); i++){ //Loop to draw rectangle around the faces//
            Mat faceROI = image(faces[i]);//Storing the face in a matrix//
            int x = faces[i].x;//Getting the initial row value of face rectangle's starting point//
            int y = faces[i].y;//Getting the initial column value of face rectangle's starting point//
            int h = y + faces[i].height;//Calculating the height of the rectangle//
            int w = x + faces[i].width;//Calculating the width of the rectangle//
            rectangle(image, Point(x, y), Point(w, h), Scalar(255, 0, 255), 2, 8, 0);//Drawing a rectangle using around the faces//
        }
        imshow("Face Detection", image);//Showing the detected face//
        waitKey(0);//To wait for keystroke to terminate the program//
        
        */

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