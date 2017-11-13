#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end
#include "common.h"
#include "Individual.cpp"
#include "Population.cpp"

int divx ;
int divy ;
int sizex;
int sizey;


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

    cout << "Divisiones en X: ";
    cin >> divx;
    cout << "Divisiones en Y: ";
    cin >> divy;

    sizex = image.cols/divx ;
    sizey = image.rows/divy ;
    srand (time(NULL));

    int bestcounter = 0;
    //int size_Population = 10;

    Individual reference(image);
    Population Pop(image);    

    namedWindow( "Ref", WINDOW_AUTOSIZE );
    namedWindow( "Best1", WINDOW_AUTOSIZE );
    namedWindow( "Best2", WINDOW_AUTOSIZE );
    namedWindow( "Best3", WINDOW_AUTOSIZE );

    cv::Mat  mat1(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat3(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 

    Individual* b1;
    Individual* b2;
    Individual* b3;


    bestcounter = 0;
    Pop.calcFitness();
    bestcounter = Pop.getBestfit();

    imshow( "Ref", image );                 
    imshow( "Best1", mat1 );  
    imshow( "Best2", mat2 );
    imshow( "Best3", mat3 );

    while( bestcounter < divx*divy){

        
        Pop.NewGen();

        Pop.calcFitness();

        bestcounter = Pop.getBestfit();

        b1 = Pop.getB1();
        b2 = Pop.getB2();
        b3 = Pop.getB3();



        b1->array_to_mat(&mat1);
        b2->array_to_mat(&mat2);
        b3->array_to_mat(&mat3);

        
        imshow( "Ref", image );                 
        imshow( "Best1", mat1 );  
        imshow( "Best2", mat2 );
        imshow( "Best3", mat3 );

        waitKey(0);

    }

    cout << "Fin\n";
    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}