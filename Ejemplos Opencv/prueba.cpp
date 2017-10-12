#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    // trying to create a matrix as same width and height as the image file being loaded.
    Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    
    int divx = 20;
    int divy = 20;

    /*

    Mat part1 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));
    Mat part2 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));
    Mat part3 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));

    for (int i=0;i<image.rows;++i){
        for(int j=0;j<image.cols;++j){
            Vec3f intensity = image.at<Vec3f>(i, j);
        
            float blue = image.at<cv::Vec3b>(i, j)[0];
            float green = image.at<cv::Vec3b>(i, j)[1];
            float red = image.at<cv::Vec3b>(i, j)[2];

            if ( 0<j && j<image.cols/3){
                part1.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0]+5;
                part1.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1]+5;
                part1.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2]+5;
            }
            if (image.cols/3<j && j<image.cols/3*2){
                part2.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0]-5;
                part2.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1]-5;
                part2.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2]-5;  
            }
            if (image.cols/3*2<j && j<image.cols){
                part3.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0];
                part3.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1];
                part3.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2];
            }

            //if (j<2 || j == image.cols/3 + 2 || j== image.cols/3 *2 + 2)
             //std::cout <<"(" << red <<"," << green <<","<< blue  << ")" << " " ;
        }
        //std::cout << std::endl;
    }
*/

/*
    Mat example(300, 300, CV_8UC3, Scalar(0, 0, 0));
    for (int i=0;i<example.rows;++i){
        for(int j=0;j<example.cols;++j){
            if ( 0<j && j<100)
                example.at<cv::Vec3b>(i, j)[0] = 255;
            if (100<j && j<200)
                example.at<cv::Vec3b>(i, j)[1] = 255;   
            if (200<j && j<300)
                example.at<cv::Vec3b>(i, j)[2] = 255;
    }

*/
    

   // cv::Size smallSize(110,70);
    std::vector<Mat> smallImages;

    int sizex = image.cols/divx ;
    int sizey = image.rows/divy ;

    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            smallImages.push_back(cv::Mat(image, rect));
        }
    }
    std::random_shuffle ( smallImages.begin(), smallImages.end() );

    int iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            smallImages[iterador].copyTo(mat2(Rect(x, y, sizex, sizey)));
            ++iterador;
            // cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            // smallImages.push_back(cv::Mat(image, rect));
        }
    }

    

    
//src.copyTo(dst(Rect(left, top, src.cols, src.rows)));



    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    namedWindow( "Display1", WINDOW_AUTOSIZE );
    imshow( "Display1", mat2 );  

    namedWindow( "Display2", WINDOW_AUTOSIZE );
    imshow( "Display2", mat2 );  

    //namedWindow( "Display3", WINDOW_AUTOSIZE );
    //imshow( "Display3", part3 );

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
