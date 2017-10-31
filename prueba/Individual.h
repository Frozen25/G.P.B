#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end

#include "common.h"



class Individual {

    private: 
        int fitness;

        std::vector<cv::Mat> image_vector;
        std::vector<int> fitness_vector;
        cv::Mat matriz;
        //cv::Mat image_array[];
        //int fitness_array[];

        void mat_to_array(cv::Mat* imageP );
        bool comparacion_cuadros(cv::Mat* mat1, cv::Mat* mat2 );

    
    public:
        Individual();
        
        Individual(cv::Mat _image);
        
        
        Individual(std::vector<cv::Mat>* images , bool x );


        Individual( std::vector<cv::Mat>* padre1 , std::vector<cv::Mat>* padre2  , std::vector<int>* fit_padre1 , std::vector<int>* fit_padre2  );


        void array_to_mat(cv::Mat* imageP );
        void randomize();
        void getFitness_Array(std::vector<cv::Mat>* original);
        void calcFitness();
        int getFitness();

        
        //cv::Mat* get_array();
        std::vector<cv::Mat>* get_vector();
        std::vector<int>* get_fit_vector();
        


        
};

#endif //INDIVIDUAL_H