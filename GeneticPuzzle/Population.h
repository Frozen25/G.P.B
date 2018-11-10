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
        Individual* ref_p;
    	Individual b1;
        Individual b2;
        Individual b3;
        int size_Population;
        int bestfit;

    public:
        Population();
        Population(cv::Mat _image , Individual* ref);
        void setref (Individual* ref);
		void calcFitness();
        void NewGen();
        Individual* getB1();
        Individual* getB2();
        Individual* getB3();
        std::vector<Individual>* getPeople();
        int getBestfit();
        void randomize();


        


        
};

#endif //POPULATION_H