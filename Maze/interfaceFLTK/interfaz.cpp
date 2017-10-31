
#include "GUI.h"
#include <iostream>
#include <fstream> 
#include <string>

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>







    
    


void play(Windows* window);







int main() {
    srand(time(0));

    Windows window(Point(w/2, 0), 600, 600, "Interfaz" );
    std::vector <Rectangle> rectangulos;
    char maze_e[30][30];

    std::string line;
    std::ifstream myfile ("m2.txt");
    if (myfile.is_open()){
        int n=0;
        while ( getline (myfile,line) ){
            for (int m=0; m < 30 ; ++m){
                //std::cout << sizeof(line) << std:: std::endl;
                maze_e[n][m] = (line[m]);
                //cout << line << '\n';
                }
            ++n;
            }
            myfile.close();
        }
    maze_e[ 23 ][ 29 ] = 'E';
    maze_e[ 15 ][ 0 ] = 'S';

    for (int i=0 ; i< 30 ; ++i){
        for (int j=0 ; j<30 ; ++j){
            if (maze_e[i][j]== '+'){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_BLACK));
                
            }
            if (maze_e[i][j]== '0'){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_WHITE));
                
            }
            if ((maze_e[i][j]== 'E')){
                rectangulos.push_back(Rectangle(Point(j*20,i*20),Point(j*20+20,i*20+20),3,FL_RED));
            }
            if ((maze_e[i][j]== 'S')){
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
    while(true){
        int i = rand() % 29 ;
        int j = rand() % 29 ;

        Rectangle rect(Point(j*20,i*20),Point((j+1)*20,(i+1)*20),3,FL_BLUE);

        window->attach(rect);
    
        
        //ServerPtr->cacheDataBase
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Fl::check();
        Fl::redraw();

        
    }
    //return 0;
    
}