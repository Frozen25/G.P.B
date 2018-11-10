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



#include "../Maze.h"



char maze_[30][30];    


void play(Windows* window);



int interfaz() {
    srand(time(0));

    Windows window(Point(w/2, 0), 650, 650, "Interfaz" );
    std::vector <Rectangle> rectangulos;
    //char maze_[30][30];

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

    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    

    int tx=0;
    int ty=0;
    Circle circle1(Point(posX*20+10,posY*20+10),10,1,FL_BLUE,FL_BLUE);
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));

    while( maze_[posY][posX] != 'E' ){

        int pointx = posX*20+10;
        int pointy = posY*20+10;
        std::cout << posX << " " << posY << std::endl;

       // if( !(tx >20)&&(tx < 24)&&(ty <6)&&(ty > 3) ) {
            //std::cout << "rect\n" ;
        //if ((pointx > -1)&&(pointx < 600)&&(pointy > -1)&&( pointy < 600)){

        circle1 = Circle(Point(posX*20+10,posY*20+10),10,1,FL_BLUE,FL_BLUE);


        //if ((posX*20 > -1)&&(posX*20<600)&&(posY*20 > -1)&&(posY*20<600)){
            //Rectangle rect(Point(posX*20,posY*20),Point(20,20),1,FL_BLUE);
         //   Circle circle1(Point(posX*20+10,posY*20+10),10,1,FL_BLUE,FL_BLUE);

        window->attach(circle1);
    
    //    }

        //tx=posX;
        //ty=posY;
        //ServerPtr->cacheDataBase

        //std::cout << "attached\n";
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        Fl::check();
        Fl::redraw();
         //std::cout << "redraw\n";

        
    }
    //return 0;
    
}

#endif //INTERFACE_H
