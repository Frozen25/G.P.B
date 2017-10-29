


using namespace cv;
using namespace std;

void mat_to_array(Mat* imageP   , Mat original_arr[] ){
    int iterador = 0;
    for (int y = 0; y < imageP->rows; y += sizey)
    {
        for (int x = 0; x < imageP->cols; x += sizex)
        {
            cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            original_arr[iterador] = cv::Mat((*imageP), rect);
            ++iterador;
        }
    }
}


void array_to_mat(Mat* imageP, Mat array[] ){
    int iterador = 0;
    for (int y = 0; y < imageP->rows; y += sizey)
    {
        for (int x = 0; x < imageP->cols; x += sizex)
        {
            array[iterador].copyTo((*imageP)(Rect(x, y, sizex, sizey)));
            ++iterador;

        }
    }
}




bool comparacion_cuadros(Mat* mat1, Mat* mat2 ){
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

void get_fitness_array(Mat padre1[], Mat original_arr[] , int fitness_array[]){
    for (int i = 0; i < divx*divy; ++i){
        if (comparacion_cuadros(&(original_arr[i]), &(padre1[i])))
            fitness_array[i] = 1;
        else
            fitness_array[i] = 0;
    }
}

int fitness_counter(int fitness[] ){
    int contador = 0;
    for (int i = 0; i < divx*divy; ++i){
     
        if(fitness[i]==1){
            ++contador;
        }
    }
    return contador;
}

void crossover(Mat padre1[] , Mat padre2[] , Mat hijo_array[] , int fit_padre1[] , int fit_padre2[]  ){
    
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