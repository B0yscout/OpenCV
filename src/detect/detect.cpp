#include "detect.h"


void PhotoAnalyser::show_image(Mat image){

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);

}

void PhotoAnalyser::show_faces(Mat image){

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

}

int PhotoAnalyser::detect_webcam(){


    cv::VideoCapture cap(0); // Open the default camera
    if(!cap.isOpened()) // Check if we succeeded
        return -1;

    cv::CascadeClassifier face_cascade;
    if(!face_cascade.load("/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml")) // Load the face detection cascade classifier
        return -1;

    cv::Mat frame;
    while(true)
    {
        cap >> frame; // Capture a frame from the camera

        std::vector<cv::Rect> faces;
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY); // Convert to grayscale for face detection
        face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30)); // Detect faces

        for(size_t i = 0; i < faces.size(); i++)
        {
            cv::rectangle(frame, faces[i], cv::Scalar(0, 0, 255), 2); // Draw rectangles around detected faces
        }

        cv::imshow("Face Detection", frame); // Display the frame with detected faces

        if(cv::waitKey(1) == 27) // Wait for the user to press 'ESC' key to exit
            break;
    }

    return 0;

}