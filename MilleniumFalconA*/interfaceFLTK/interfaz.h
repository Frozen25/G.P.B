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
#include "../vars.h"
//#include "Asteroides.cpp"

void update(Windows* window);

void drawmat(Windows* window );

int interfaz() {

    

    Windows window(Point(w/2, 0), 600, 600, "Interfaz" );

    //drawmat(&window);
    update(&window);
    return Fl::run();
}

void drawmat(Windows* window ){
    //Windows window(Point(w/2, 0), 600, 600, "Interfaz" );
    std::vector <Rectangle> rectangulos;

    for (int i=0 ; i< 60 ; ++i){
        for (int j=0 ; j<60 ; ++j){
            if (map[j][i]== '0'){
                rectangulos.push_back(Rectangle(Point(j*10,i*10),Point(j*10+10,i*10+10),3,FL_BLACK));
            }
            if (map[j][i]== '.'){
                rectangulos.push_back(Rectangle(Point(j*10,i*10),Point(j*10+10,i*10+10),3,FL_WHITE));
            }
        }
    }

    for ( int i=0 ; i < rectangulos.size() ; ++i){
        window->attach(rectangulos[i]);
    }
}

void update(Windows* window){


    std::vector <Rectangle> rectangulos;

        for (int i=0 ; i< 60 ; ++i){
            for (int j=0 ; j<60 ; ++j){
                if (map[j][i]== 1){
                    rectangulos.push_back(Rectangle(Point(j*10,i*10),Point(10,10),3,FL_WHITE));
                }
                
            }
        }

        for ( int i=0 ; i < rectangulos.size() ; ++i){
            window->attach(rectangulos[i]);
        }

        
        //std::vector <Asteroides> Mets;
        //for (int i=0 ; i< num_met ; ++i){
       //     Mets.push_back(Asteroides(xMet[i],yMet[i]));
       // }


    while ( true){

        rectangulos.clear();
        for (int i=0 ; i< 60 ; ++i){
            for (int j=0 ; j<60 ; ++j){
                if (map[j][i]== 1){
                    rectangulos.push_back(Rectangle(Point(j*10,i*10),Point(10,10),3,FL_WHITE));
                }
                
            }
        }

        for ( int i=0 ; i < rectangulos.size() ; ++i){
            window->attach(rectangulos[i]);
        }
        


        Rectangle Start(Point(xStart*10,yStart*10),Point(10,10),1,FL_BLUE);
        Rectangle Goal(Point(xGoal*10,yGoal*10),Point(10,10),1,FL_RED);
        window->attach(Start);
        window->attach(Goal);

        
   //     for (int i=0 ; i< num_met ; ++i){
    ////        Mets[i].update(i);
     //       Mets[i].draw(window);
     //   }


        Circle circle1(Point(xPlayer*10+5,yPlayer*10+5),5,1,FL_BLUE,FL_BLUE);
        Circle circle2(Point(xTF1*10+5,yTF1*10+5),5,1,FL_MAGENTA,FL_WHITE);
        Circle circle3(Point(xTF2*10+5,yTF2*10+5),5,1,FL_CYAN,FL_WHITE);

        window->attach(circle1);
        window->attach(circle2);
        window->attach(circle3);

        Circle mcircle1(Point(xMet[0]*10+5,yMet[0]*10+5),5,1,FL_YELLOW,FL_RED);
        Circle mcircle2(Point(xMet[1]*10+5,yMet[1]*10+5),5,1,FL_YELLOW,FL_RED);
        Circle mcircle3(Point(xMet[2]*10+5,yMet[2]*10+5),5,1,FL_YELLOW,FL_RED);

        window->attach(mcircle1);
        window->attach(mcircle2);
        window->attach(mcircle3);

      //  for (int i=0 ; i< num_met ; ++i){
     ////       Mets[i].update(i);
        //    Mets[i].draw(window);
      //  }
   //     for (int i=0 ; i< num_met ; ++i){
   //         Circle *circlen = new Circle(Point(xMet[i]*10+5,yMet[i]*10+5),10,1,FL_RED,FL_RED);
  //          window->attach(*circlen);
    //    }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        Fl::check();
        Fl::redraw();

        
    }
    //return 0;
    
}

#endif //INTERFACE_H
