

#include "Population.h"
#include <iostream>     // std::std::cout
Population::Population(){}

Population::Population(cv::Mat _image , Individual* ref){
    Reference = Individual(_image.clone());
    size_Population = 20;
    People.resize(size_Population);
    std::vector<Individual>  People(size_Population, Individual(Reference.get_vector() , true));
    for (int m = 0; m < size_Population ; ++m){
        Individual* temp = &People[m];
        temp->randomize();
    }
    //std::cout<< "end" << std::endl;
}

void Population::randomize(){
    for (int m = 0; m < size_Population ; ++m){
            (People[m]).randomize();
        }
}
void Population::setref(Individual* ref){
    ref_p = ref;
}

void Population::calcFitness() {
    std::cout << "calc fit vector " << std::endl;
    int max1=0;
    int max2=0;
    int max3=0;

    for (int m = 0; m < size_Population ; ++m){
        std::cout << m << std::endl;
        Individual* temp = &People[m];
        
        temp->getFitness_Array(Reference.get_vector());
        temp->calcFitness();
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
    bestfit = max1;
    std::cout << std::endl;
    std::cout << "Best: " << max3 << " , " << max2 << " , " << max1 << std::endl;



}

std::vector<Individual>* Population::getPeople(){
    return &People;
}

int Population::getBestfit(){
    return bestfit;
}

void Population::NewGen(){
    //std::vector<Individual> newPeople;
    //newPeople.resize(size_Population);

    int m=0;
    for (; m < size_Population/2 ; ++m){
        People[m] = Individual(b1.get_vector() , b2.get_vector() , b1.get_fit_vector() , b2.get_fit_vector());
    }
    for (; m < 3*size_Population/4 ; ++m){
        People[m] = Individual(b3.get_vector() , b2.get_vector() , b3.get_fit_vector() , b2.get_fit_vector());
    }
    for (; m < size_Population ; ++m){
        People[m] = Individual(b1.get_vector() , b3.get_vector() , b1.get_fit_vector() , b3.get_fit_vector());
    }
    //People = newPeople;

}

Individual* Population::getB1(){
    return &b1;
}

Individual* Population::getB2(){
    return &b2;
}

Individual* Population::getB3(){
    return &b3;
}

