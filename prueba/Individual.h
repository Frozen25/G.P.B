#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include "common.h"


class Individual {

    private: 
        int fitness = 0;
        Mat image_array[divx*divy];
        int fitness_array[divx*divy];

        void mat_to_array(Mat* imageP );

    
    public:
        Individual();
        Individual(Mat _image);
        Individual(Mat images[divx*divy] );
        Individual (Mat padre1[] , Mat padre2[]  , int fit_padre1[] , int fit_padre2[]  );

        void randomize();
        void getFitness_Array(Mat original[]);
        int getFitness();
        
}