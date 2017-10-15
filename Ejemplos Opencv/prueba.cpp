#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector


using namespace cv;
using namespace std;

void eq_block(Mat i1 , Mat i2){
    int i = i1.cols;
    int j = i1.rows;
    if (i1.at<cv::Vec3b>(i, j)[0] == i2.at<cv::Vec3b>(i, j)[0])
        std::cout << 1 << std::endl;
}


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

    srand (time(NULL));
    // trying to create a matrix as same width and height as the image file being loaded.
    Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    
    int divx = 2;
    int divy = 2;

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



   // cv::Size smallSize(110,70);
    std::vector<Mat> smallImages;

    int sizex = image.cols/divx ;
    int sizey = image.rows/divy ;

    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            //std::cout << (int)image.at<cv::Vec3b>(x, y)[0] << std::endl;
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

    
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    namedWindow( "Display1", WINDOW_AUTOSIZE );
    imshow( "Display1", mat2 );  

    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {

            if(    (int)mat2.at<cv::Vec3b>(y, x)[0] == (int)image.at<cv::Vec3b>(y, x)[0]
                && (int)mat2.at<cv::Vec3b>(y, x)[1] == (int)image.at<cv::Vec3b>(y, x)[1]
                && (int)mat2.at<cv::Vec3b>(y, x)[2] == (int)image.at<cv::Vec3b>(y, x)[2]

               
                 && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] 
                 && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1]  
                 && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]

                ){
                std:: cout << 1 << "\t" ;
            }
            else
                std:: cout << 0 << "\t";


/*
            //i1.at<cv::Vec3b>(i, j)[0] == i2.at<cv::Vec3b>(i, j)[0])
            std:: cout << "B: " << x <<"," << y << "    \t" ;

            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[0] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[0] << "    \t";

            std:: cout << "R: "  << x <<"," << y << "    \t" ;
            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[1] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[1] << "    \t";

            std:: cout << "G: "  << x <<"," << y << "    \t" ;
            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[2] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[2] << std::endl;


            std::cout << y << " , " << x << "\n"
                << "\tB: " << (int)mat2.at<cv::Vec3b>(y, x)[0] << "-" << (int)image.at<cv::Vec3b>(y, x)[0] << "- \n" 
                << "\tR: " << (int)mat2.at<cv::Vec3b>(y, x)[1] << "-" << (int)image.at<cv::Vec3b>(y, x)[1] << "- \n" 
                << "\tG: " << (int)mat2.at<cv::Vec3b>(y, x)[2] << "-" << (int)image.at<cv::Vec3b>(y, x)[2] << "- \n" 

               
                << "\tB: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] << "- \n" 
                << "\tR: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] << "- \n" 
                << "\tG: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]
                ;
                std:: cout << std:: endl;
                */
    
            
        }
        std::cout << "\n";
    }



    

    
//src.copyTo(dst(Rect(left, top, src.cols, src.rows)));



   

    //namedWindow( "Display3", WINDOW_AUTOSIZE );
    //imshow( "Display3", part3 );

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}