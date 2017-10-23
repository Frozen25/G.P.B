

Individual::Individual(){
        
    }

Individual::Individual(Mat* _image ){
    image_array[divx*divy];
    fitness_array[divx*divy];
    mat_to_array(_image);
}

Individual::Individual(Mat images[divx*divy] ){
    image_array = images;
    fitness_array[divx*divy];
    random_shuffle( &(image_array[0]), &(image_array[divx*divy-1]));
}


Individual::Individual (Mat padre1[] , Mat padre2[]  , int fit_padre1[] , int fit_padre2[]  ){

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
                Mat  black(sizey, sizex,CV_8UC3,Scalar(0, 0, 0)); 
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


void Individual::randomize(){
    random_shuffle( &(image_array[0]), &(image_array[divx*divy-1]));
}

void Individual::getFitness_Array(Mat original[]){
    for (int i = 0; i < divx*divy; ++i){
        if (comparacion_cuadros(&(image_array[i]), &(original[i])))
            fitness_array[i] = 1;
        else
            fitness_array[i] = 0;
    }
}

int Individual::getFitness(){
    int contador = 0;
    for (int i = 0; i < divx*divy; ++i){
     
        if(fitness_array[i]==1){
            ++contador;
        }
    }
    return contador;
}

void Individual::mat_to_array(Mat* imageP ){
    int iterador = 0;
    for (int y = 0; y < imageP->rows; y += sizey)
    {
        for (int x = 0; x < imageP->cols; x += sizex)
        {
            cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            image_array[iterador] = cv::Mat((*imageP), rect);
            ++iterador;
        }
    }
}