#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end
#include "common.h"
#include "Individual.cpp"
#include "Population.cpp"

int divx = 4;
int divy = 2;
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

    sizex = image.cols/divx ;
    sizey = image.rows/divy ;
    srand (time(NULL));

    //Individual reference(image);
    int contador = 0;

    Population population(image);

    std::cout << "created population\n";

    cv::Mat  mat1(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat3(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 

    namedWindow( "Reference", WINDOW_AUTOSIZE );
    namedWindow( "Best 1", WINDOW_AUTOSIZE );
    namedWindow( "Best 2", WINDOW_AUTOSIZE );
    namedWindow( "Best 3", WINDOW_AUTOSIZE );

    Individual Reference(image);

    int max1=0;
    int max2=0;
    int max3=0;

    int size_Population = 20;


    Individual* b1;
    Individual* b2;
    Individual* b3;

    for (int m = 0; m < size_Population ; ++m){

        Individual* temp = &((population.getPeople())->at(m));
        std::cout << "got temp*\n";

        temp->getFitness_Array(Reference.get_vector());
        std::cout << "made fit vector \n";

        temp->calcFitness();
        std::cout << "calculated fit\n";

        int fit = temp->getFitness();
        std::cout << fit << " ";

        if (fit > max1)
        {
            max3 = max2;    b3 = b2;
            max2 = max1;    b2 = b1;
            max1 = fit;     b1 = temp;
        }
        else if (fit > max2)
        {
            max3 = max2;    b3 = b2;
            max2 = fit;     b2 = temp;
        }
        else if (fit > max3)
        {
            max3 = fit;     b3 = temp;
        }

    }
    std::cout << std::endl;
    std::cout << "Best: " << max3 << " , " << max2 << " , " << max1 << std::endl;



   
   


    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}