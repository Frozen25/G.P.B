//interfaz.h
#ifndef INTERFACE_H
#define INTERFACE_H

#include "GUI.h"
#include <iostream>
#include "../common.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>







    
    


void play(Windows* window);



int interfaz() {
    srand(time(0));

    Windows window(Point(w/2, 0), 600, 600, "Interfaz" );
    std::vector <Rectangle> rectangulos;
    char maze_[30][30];

    std::string line;
    std::ifstream myfile ("m2.txt");
    if (myfile.is_open()){
        int n=0;
        while ( getline (myfile,line) ){
            for (int m=0; m < 30 ; ++m){
                //std::cout << sizeof(line) << std:: std::endl;
                maze_[n][m] = (line[m]);
                //cout << line << '\n';
                }
            ++n;
            }
            myfile.close();
        }
    maze_[ 23 ][ 29 ] = 'E';
    maze_[ 15 ][ 0 ] = 'S';

    for (int i=0 ; i< 30 ; ++i){
        for (int j=0 ; j<30 ; ++j){
            if (maze_[i][j]== '+'){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_BLACK));
                
            }
            if (maze_[i][j]== '0'){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_WHITE));
                
            }
            if ((maze_[i][j]== 'E')){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_RED));
            }
            if ((maze_[i][j]== 'S')){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_GREEN));
            }
        }
    }

    for ( int i=0 ; i < rectangulos.size() ; ++i){
        window.attach(rectangulos[i]);
    }

    //std::thread functionThread(play, &window );
    //functionThread.detach();
    play(&window);


    return Fl::run();
}

void play(Windows* window){
    while( (posX!=23)&&(posY!=29) ){

        int posX_ = posX;
        int posY_ = posY;
        //Circle circle1(Point(posX_*20+0,posY_*20+0),10,1,FL_BLUE,FL_BLUE);


        //if ((posX_*20 > -1)&&(posX_*20<600)&&(posY_*20 > -1)&&(posY_*20<600)){
            //Rectangle rect(Point(posX_*20,posY_*20),Point(20,20),1,FL_BLUE);
         //   Circle circle1(Point(posX_*20+10,posY_*20+10),10,1,FL_BLUE,FL_BLUE);

         //   window->attach(circle1);
    
       // }
        //ServerPtr->cacheDataBase
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        Fl::check();
        Fl::redraw();

        
    }
    //return 0;
    
}

#endif //INTERFACE_H
