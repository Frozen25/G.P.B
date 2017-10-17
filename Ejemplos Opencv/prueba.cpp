#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <iterator> // for std::begin, std::end


using namespace cv;
using namespace std;

void comparacion_mat(Mat* image, Mat* mat2 , int sizex , int sizey){
    for (int y = 0; y < image->rows; y += sizey){
        for (int x = 0; x < image->cols; x += sizex){
            if(    
                //compara primer pixel del cuadro
                   (int)mat2->at<cv::Vec3b>(y, x)[0] == (int)image->at<cv::Vec3b>(y, x)[0]
                && (int)mat2->at<cv::Vec3b>(y, x)[1] == (int)image->at<cv::Vec3b>(y, x)[1]
                && (int)mat2->at<cv::Vec3b>(y, x)[2] == (int)image->at<cv::Vec3b>(y, x)[2]

                //compara pixel del centro del cuadro
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] 
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1]  
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]
                ){
                std:: cout << 1 << "\t" ;
            }
            else
                std:: cout << 0 << "\t";    
            
        }
        std::cout << "\n";
    }
}

bool comparacion_cuadros(Mat* mat1, Mat* mat2 , int sizex , int sizey){
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


/*
std::vector<std::vector<int>>  comparacion_mat2(Mat* image, Mat* mat2 , int sizex , int sizey ){
    int rows = image->rows/sizey
    int cols = image->cols/sizex;
    std::vector<std::vector<int>> array_2d(rows, std::vector<int>(cols, 0));

    for (int y = 0; y < image->rows; y += sizey){
        for (int x = 0; x < image->cols; x += sizex){
            if(    
                //compara primer pixel del cuadro
                   (int)mat2->at<cv::Vec3b>(y, x)[0] == (int)image->at<cv::Vec3b>(y, x)[0]
                && (int)mat2->at<cv::Vec3b>(y, x)[1] == (int)image->at<cv::Vec3b>(y, x)[1]
                && (int)mat2->at<cv::Vec3b>(y, x)[2] == (int)image->at<cv::Vec3b>(y, x)[2]

                //compara pixel del centro del cuadro
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] 
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1]  
                && (int)mat2->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] == (int)image->at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]
                ){
                std:: cout << 1 << "\t" ;
                array_2d.at(y/sizey).at(x/sizex) = 1;
            }
            else
                std:: cout << 0 << "\t"; 
                array_2d.at(y/sizey).at(x/sizex) = 0;   
            
        }
        std::cout << "\n";
    }
    return array_2d;
}
*/

void juntar_img(Mat* image, Mat* mat2 , Mat* mat3 , int sizex , int sizey){
    Mat  mat4(image->rows, image->cols,CV_8UC3,Scalar(0, 0, 0)); 



}


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

    srand (time(NULL));
    // trying to create a matrix as same width and height as the image file being loaded.
    Mat  mat2(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    Mat  mat3(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 
    
    int divx = 4;
    int divy = 2;

    /*

    Mat part1 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));
    Mat part2 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));
    Mat part3 (image.rows, image.cols/3, CV_8UC3, Scalar(0, 0, 0));

    for (int i=0;i<image.rows;++i){
        for(int j=0;j<image.cols;++j){
            Vec3f intensity = image.at<Vec3f>(i, j);
        
            float blue = image.at<cv::Vec3b>(i, j)[0];
            float green = image.at<cv::Vec3b>(i, j)[1];
            float red = image.at<cv::Vec3b>(i, j)[2];

            if ( 0<j && j<image.cols/3){
                part1.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0]+5;
                part1.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1]+5;
                part1.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2]+5;
            }
            if (image.cols/3<j && j<image.cols/3*2){
                part2.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0]-5;
                part2.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1]-5;
                part2.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2]-5;  
            }
            if (image.cols/3*2<j && j<image.cols){
                part3.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0];
                part3.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1];
                part3.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2];
            }

            //if (j<2 || j == image.cols/3 + 2 || j== image.cols/3 *2 + 2)
             //std::cout <<"(" << red <<"," << green <<","<< blue  << ")" << " " ;
        }
        //std::cout << std::endl;
    }
*/



   // cv::Size smallSize(110,70);
    std::vector<Mat> original_vect;
    Mat original_arr[divx*divy];

    int sizex = image.cols/divx ;
    int sizey = image.rows/divy ;

    int iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            original_vect.push_back(cv::Mat(image, rect));
            original_arr[iterador] = cv::Mat(image, rect);
            ++iterador;
        }
    }

    //std::vector<Mat> smallImages(original_vect);
    Mat smallImages[divx*divy] ;

    Mat mat3_vect[divx*divy] ;

    //std::vector<Mat> mat3_vect(original_vect);

    std::vector<Mat> smallImagesV (original_vect);
    std::vector<Mat> mat3V (original_vect);

    std::random_shuffle ( smallImagesV.begin(), smallImagesV.end() );

    std::random_shuffle ( mat3V.begin(), mat3V.end() );

    std::copy(smallImagesV.begin(), smallImagesV.end(), smallImages);
    std::copy(mat3V.begin(), mat3V.end(), mat3_vect);
    
    


//crear matrices apartir del array de imagenes
    iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            smallImages[iterador].copyTo(mat2(Rect(x, y, sizex, sizey)));
            ++iterador;
            // cv::Rect rect =  cv::Rect(x,y, sizex, sizey);
            // smallImages.push_back(cv::Mat(image, rect));
        }
    }

    iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            mat3_vect[iterador].copyTo(mat3(Rect(x, y, sizex, sizey)));
            ++iterador;
        }
    }




    int int_original[divx*divy];
    Mat hijo_array[divx*divy];

    Mat  mat_hijo(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 


    iterador = 0;
    for (int i = 0; i < divx*divy; ++i){

            bool smallImages_original_vect  = comparacion_cuadros(&original_vect[i], &smallImages[i] , sizex, sizey );

            bool mat3_vect_original_vect    = comparacion_cuadros(&original_vect[i], &mat3_vect[i] , sizex, sizey );


            if(    smallImages_original_vect   ){
                hijo_array[i] = (smallImages[i]);
                int_original[i] = (1);
                }

            if (   mat3_vect_original_vect && !smallImages_original_vect ){
                hijo_array[i] = (mat3_vect[i]);
                int_original[i] = (1);
            }
            
            if (!smallImages_original_vect && !mat3_vect_original_vect ){
                int_original[i] = (0);
            }        
    }

    
    Mat  mat_hijo0(image.rows, image.cols,CV_8UC3,Scalar(0, 0, 0)); 

    iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            if (int_original[iterador] == (1))
                hijo_array[iterador].copyTo(mat_hijo0(Rect(x, y, sizex, sizey)));
            ++iterador;
        }
    }
    

    

    
    for (int i = 0; i < divx*divy; ++i){

        bool utilizada1 = false;
        bool utilizada2 = false;

        for(int j=0 ; j<divx*divy; ++j ){
            if ((comparacion_cuadros(&original_vect[j], &smallImages[i] , sizex, sizey )) && int_original[j] == 1 )
            {
                std::cout << "imagen1 [" << i << "] coincide con la original[" << j << "] y ya fue utilizada\n";
                utilizada1 = true;

            }
            if ((comparacion_cuadros(&original_vect[j], &mat3_vect[i] , sizex, sizey )) && int_original[j] == 1 )
            {
                std::cout << "imagen2 [" << i << "] coincide con la original[" << j << "] y ya fue utilizada\n";
                utilizada2 = true;

            }
            
        }
        if(int_original[i] == 0)
        {
            if (utilizada1)
                hijo_array[i] = mat3_vect[i];

            if (utilizada2)
                hijo_array[i] = smallImages[i];

            if (!utilizada1 && !utilizada2){

                const size_t numElements = sizeof (hijo_array) / sizeof (hijo_array[0]);

                Mat* end = hijo_array + numElements;

                bool exists1 = false;
                bool exists2 = false;


                // for(int j=0 ; j<divx*divy; ++j ){
                //     if( comparacion_cuadros( &hijo_array[j],  &mat3_vect[i] ,  sizex ,  sizey) )
                //         exists1 = true;
                //     if( comparacion_cuadros( &hijo_array[j],  &smallImages[i] ,  sizex ,  sizey) )
                //         exists2 = true;
                // }
                

                if (exists1)
                    hijo_array[i] = smallImages[i];
                if (exists2)
                    hijo_array[i] = mat3_vect[i];
                if (!exists2 && !exists1){
                    int randNum = rand()%(1-0 + 1) + 0;
                    if (randNum == 1)
                        hijo_array[i] = mat3_vect[i];
                    else
                        hijo_array[i] = smallImages[i];
                }
                    
            }

        }
      
    }

    iterador = 0;
    for (int y = 0; y < image.rows; y += sizey)
    {
        for (int x = 0; x < image.cols; x += sizex)
        {
            
            hijo_array[iterador].copyTo(mat_hijo(Rect(x, y, sizex, sizey)));
            ++iterador;
        }
    }
    
        
    



    
/*

    for (int y = 0; y < image.rows; y += sizey){
        for (int x = 0; x < image.cols; x += sizex){
            if(    
                //compara primer pixel del cuadro
                   (int)mat2.at<cv::Vec3b>(y, x)[0] == (int)image.at<cv::Vec3b>(y, x)[0]
                && (int)mat2.at<cv::Vec3b>(y, x)[1] == (int)image.at<cv::Vec3b>(y, x)[1]
                && (int)mat2.at<cv::Vec3b>(y, x)[2] == (int)image.at<cv::Vec3b>(y, x)[2]

                //compara pixel del centro del cuadro
                && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] 
                && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1]  
                && (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] == (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]
                ){
                std:: cout << 1 << "\t" ;
            }
            else
                std:: cout << 0 << "\t";



            //i1.at<cv::Vec3b>(i, j)[0] == i2.at<cv::Vec3b>(i, j)[0])
            std:: cout << "B: " << x <<"," << y << "    \t" ;

            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[0] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[0] << "    \t";

            std:: cout << "R: "  << x <<"," << y << "    \t" ;
            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[1] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[1] << "    \t";

            std:: cout << "G: "  << x <<"," << y << "    \t" ;
            std::cout << (int)mat2.at<cv::Vec3b>(x, y)[2] << " - ";
            std::cout << (int)image.at<cv::Vec3b>(x, y)[2] << std::endl;


            std::cout << y << " , " << x << "\n"
                << "\tB: " << (int)mat2.at<cv::Vec3b>(y, x)[0] << "-" << (int)image.at<cv::Vec3b>(y, x)[0] << "- \n" 
                << "\tR: " << (int)mat2.at<cv::Vec3b>(y, x)[1] << "-" << (int)image.at<cv::Vec3b>(y, x)[1] << "- \n" 
                << "\tG: " << (int)mat2.at<cv::Vec3b>(y, x)[2] << "-" << (int)image.at<cv::Vec3b>(y, x)[2] << "- \n" 

               
                << "\tB: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[0] << "- \n" 
                << "\tR: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[1] << "- \n" 
                << "\tG: " << (int)mat2.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2] << "-" << (int)image.at<cv::Vec3b>(y+sizey/2, x+sizex/2)[2]
                ;
                std:: cout << std:: endl;
                
    
            
        }
        std::cout << "\n";
    }
*/

    //comparacion_mat(&image , &mat2, sizex, sizey);

    
    

    
//src.copyTo(dst(Rect(left, top, src.cols, src.rows)));

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    namedWindow( "Display1", WINDOW_AUTOSIZE );
    imshow( "Display1", mat2 );  

    namedWindow( "Display2", WINDOW_AUTOSIZE );
    imshow( "Display2", mat3 );

    namedWindow( "Display Hijo", WINDOW_AUTOSIZE );
    imshow( "Display Hijo", mat_hijo );

    namedWindow( "Display Hijo0", WINDOW_AUTOSIZE );
    imshow( "Display Hijo0", mat_hijo0 );



    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}