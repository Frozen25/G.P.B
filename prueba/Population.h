//Population.h

#ifndef POPULATION_H
#define POPULATION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end

#include "common.h"
#include "Individual.h"


class Population {

    private:         
    	std::vector<Individual> People;
    	//std::vector<Individual*> Raza_Aria;
    	Individual Reference;
    	Individual* b1;
        Individual* b2;
        Individual* b3;
        int size_Population;

    public:
        Population();
        Population(cv::Mat _image);
		void calcFitness();
        void NewGen();
        Individual* getB1();
        Individual* getB2();
        Individual* getB3();
        std::vector<Individual>* getPeople();
        

        


        
};

#endif //POPULATION_H