#include "Individual.h"



Individual::Individual(){
    fitness = 0;
    fitness_vector.resize(divx*divy);
    image_vector.resize(divx*divy);
    //image_array[divx*divy];
    //fitness_array[divx*divy];
}



Individual::Individual(cv::Mat _image ){

    
    fitness = 0;
    fitness_vector.resize(divx*divy);
    image_vector.resize(divx*divy);
    //image_array[divx*divy];
    //fitness_array[divx*divy];

    std::cout << "mat -> array \n";
    mat_to_array(&_image);
}




Individual::Individual(std::vector<cv::Mat>* images , bool x){

    fitness_vector.resize(divx*divy);
    image_vector.resize(divx*divy);

    image_vector = *images;

    std::random_shuffle( &(image_vector[0]), &(image_vector[divx*divy-1]));

}

/*
Individual::Individual (cv::Mat padre1[] , cv::Mat padre2[]  , int fit_padre1[] , int fit_padre2[]  ){

    fitness = 0;

    image_array[divx*divy];

    fitness_array[divx*divy];
    
    int int_original[divx*divy];
    for (int i = 0; i < divx*divy; ++i){

            //bool padre1_original_vect  = comparacion_cuadros(&original_arr[i], &padre1[i]  );

            //bool padre2_original_vect    = comparacion_cuadros(&original_arr[i], &padre2[i]  );


            if(    fit_padre1[i]   ){
                hijo_array[i] = (padre1[i]);
                //int_original[i] = (1);
                }

            if (   (fit_padre2[i]) && !(fit_padre1[i]) ){
                hijo_array[i] = (padre2[i]);
                //int_original[i] = (1);
            }
            
            if (!(fit_padre1[i]) && !(fit_padre2[i]) ){
                cv::Mat  black(sizey, sizex,CV_8UC3,Scalar(0, 0, 0)); 
                hijo_array[i] = black ; 
                //int_original[i] = (0);
            }        
    }

    std::vector<Mat> randomHijo;
    for (int i = 0; i < divx*divy; ++i){

        bool utilizada1 = false;

        for(int j=0 ; j<divx*divy; ++j ){
            //std::cout << "imagen["<< i << "]" << " hijo["<< j <<"]\n";

            if ((comparacion_cuadros(&hijo_array[j], &padre1[i]  ))){
                //std::cout << "imagen[" << i << "] coincide con hijo[" << j << "]\n"; 
                utilizada1 = true;
            }
   
        }
        if (!utilizada1){
            randomHijo.push_back(padre1[i]);
        }
    }

    //  std::cout << "resto genes en vector\n";

    std::random_shuffle ( randomHijo.begin(), randomHijo.end() );

    //std::cout << "shuffle resto genes  - vectSize" << randomHijo.size() <<  "\n";

    int iterador = 0;
    for (int i=0 ; i< divx*divy ; ++i){
        if (!(fit_padre1[i]) && !(fit_padre2[i]) ){
           // std::cout << iterador << endl;
            hijo_array[i] = randomHijo.at(iterador);
            ++iterador;
        }

    }

}

*/

void Individual::randomize(){
    std::random_shuffle( &(image_vector[0]), &(image_vector[divx*divy-1]));
}


void Individual::getFitness_Array(std::vector<cv::Mat>* original){
    for (int i = 0; i < divx*divy; ++i){
        if (comparacion_cuadros(&(image_vector[i]), &(original->at(i)) ) )
            fitness_vector[i] = 1;
        else
            fitness_vector[i] = 0;
    }
}


void Individual::calcFitness(){
    int contador = 0;
        for (int i = 0; i < divx*divy; ++i){
            if(fitness_vector[i]==1){
                ++contador;
            }
        }
        fitness = contador;
}


int Individual::getFitness(){
    return fitness;
}



void Individual::array_to_mat(cv::Mat* imageP ){
    int iterador = 0;
    for (int y = 0; y < imageP->rows; y += sizey)
    {
        for (int x = 0; x < imageP->cols; x += sizex)
        {
            image_vector.at(iterador).copyTo((*imageP)(cv::Rect(x, y, sizex, sizey)));
            ++iterador;

        }
    }
}



void Individual::mat_to_array(cv::Mat* imageP ){


    int iterador = 0;
    for (int y = 0; y < imageP->rows; y += sizey)
    {
        for (int x = 0; x < imageP->cols; x += sizex)
        {
            cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            image_vector[iterador] = cv::Mat((*imageP), rect);
            ++iterador;
        }
    }
}

/*

cv::Mat* Individual::get_array(){
    return image_array;
}


*/

std::vector<cv::Mat>* Individual::get_vector(){
    return &image_vector;
}

bool Individual::comparacion_cuadros(cv::Mat* mat1, cv::Mat* mat2 ){
    if(    
                //compara primer pixel del cuadro
                   (int)mat2->at<cv::Vec3b>(0, 0)[0] == (int)mat1->at<cv::Vec3b>(0, 0)[0]
                && (int)mat2->at<cv::Vec3b>(0, 0)[1] == (int)mat1->at<cv::Vec3b>(0, 0)[1]
                && (int)mat2->at<cv::Vec3b>(0, 0)[2] == (int)mat1->at<cv::Vec3b>(0, 0)[2]

                //compara pixel del centro del cuadro
                && (int)mat2->at<cv::Vec3b>(sizey/2, sizex/2)[0] == (int)mat1->at<cv::Vec3b>(sizey/2, sizex/2)[0] 
                && (int)mat2->at<cv::Vec3b>(sizey/2, sizex/2)[1] == (int)mat1->at<cv::Vec3b>(sizey/2, sizex/2)[1]  
                && (int)mat2->at<cv::Vec3b>(sizey/2, sizex/2)[2] == (int)mat1->at<cv::Vec3b>(sizey/2, sizex/2)[2]
                )
        return true;
    else
        return false;
}

