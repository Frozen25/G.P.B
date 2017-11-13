#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end
#include "common.h"
#include "Individual.cpp"

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
    int size_Population = 10;
    Individual reference(image);
    

    namedWindow( "Ref", WINDOW_AUTOSIZE );
    namedWindow( "Best1", WINDOW_AUTOSIZE );
    namedWindow( "Best2", WINDOW_AUTOSIZE );
    namedWindow( "Best3", WINDOW_AUTOSIZE );

    cv::Mat  mat1(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    cv::Mat  mat3(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 

    Individual b1;
    Individual b2;
    Individual b3;


    std::vector<Individual>  Poblacion(size_Population, Individual(reference.get_vector() , true));

    for (int m = 0; m < size_Population ; ++m){
        Individual* temp = &Poblacion[m];
        temp->randomize();
    }
    

    int max1=0;
    int max2=0;
    int max3=0;

    for (int m = 0; m < size_Population ; ++m){

        Individual* temp = &(Poblacion[m]);
        //std::cout << "got temp*\n";

        temp->getFitness_Array(reference.get_vector());
        //std::cout << "made fit vector \n";

        temp->calcFitness();
        //std::cout << "calculated fit\n";

        int fit = temp->getFitness();
        std::cout << fit << " ";

        if (fit > max1)
        {
            max3 = max2;    b3 = b2;
            max2 = max1;    b2 = b1;
            max1 = fit;     b1 = *temp;
        }
        else if (fit > max2)
        {
            max3 = max2;    b3 = b2;
            max2 = fit;     b2 = *temp;
        }
        else if (fit > max3)
        {
            max3 = fit;     b3 = *temp;
        }

    }
    cout << endl;
    bestcounter = max1;

    b1.array_to_mat(&mat1);
    b2.array_to_mat(&mat2);
    b3.array_to_mat(&mat3);

    
    imshow( "Ref", image );                 
    imshow( "Best1", mat1 );  
    imshow( "Best2", mat2 );
    imshow( "Best3", mat3 );



    int _m = 0;


    std::vector<Individual>  newPeople(size_Population, Individual());

    cout << _m ;
    
    for ( ; bestcounter < divx*divy ;){
        std::vector<Individual>  TPeople(size_Population, Individual());
        _m =0;
        cout << _m ;
        for ( ; _m <   size_Population/2 ; ++_m){
            cout << _m ;
            TPeople[_m] = Individual(b1.get_vector() , b2.get_vector() , b1.get_fit_vector() , b2.get_fit_vector());
        }
        for ( ; _m < 3*size_Population/4 ; ++_m){
            cout << _m ;
            TPeople[_m] = Individual(b3.get_vector() , b2.get_vector() , b3.get_fit_vector() , b2.get_fit_vector());
        }
        for ( ; _m <     size_Population ; ++_m){
            cout << _m ;
            TPeople[_m] = Individual(b1.get_vector() , b3.get_vector() , b1.get_fit_vector() , b3.get_fit_vector());
        }
        cout << endl;
        newPeople = TPeople;
        

        for (int m = 0; m < size_Population ; ++m){

            Individual* temp = &(newPeople[m]);
            //std::cout << "got temp*\n";

            temp->getFitness_Array(reference.get_vector());
            //std::cout << "made fit vector \n";

            temp->calcFitness();
            //std::cout << "calculated fit\n";

            int fit = temp->getFitness();
            std::cout << fit << " ";

            if (fit > max1)
            {
                max3 = max2;    b3 = b2;
                max2 = max1;    b2 = b1;
                max1 = fit;     b1 = *temp;
            }
            else if (fit > max2)
            {
                max3 = max2;    b3 = b2;
                max2 = fit;     b2 = *temp;
            }
            else if (fit > max3)
            {
                max3 = fit;     b3 = *temp;
            }

        }
        cout << endl;
        bestcounter = max1;

        b1.array_to_mat(&mat1);
        b2.array_to_mat(&mat2);
        b3.array_to_mat(&mat3);

        
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