


#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <thread>
#include <chrono>
#include "recipe.h"
#include "common.h"
#include <unistd.h>
#include "interfaceFLTK/interfaz.h"
#include "vars.h"

int xStart, yStart, xGoal, yGoal, xPlayer, yPlayer, xTF1, yTF1, xTF2, yTF2;
int xMET1, yMET1, xMET2, yMET2, xMET3, yMET3, xMET4, yMET4;
//numero de meteoritos
int xMet[num_met] , yMet[num_met];
string route="";
string route1="";
string route2="";
int interfaz();
void function_();


int main()
{
    srand(time(NULL));

    // create empty map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) map[x][y]=0;
    }

    // fillout the map matrix with a '+' pattern
    for(int x=n/8;x<n*7/8;x++)
    {
        map[x][m/2]=1;
    }
    for(int y=0;y<m*7/8;y++)
    {
        map[n/2][y]=1;
    }
    
    
    //std::vector <pair> Meteors;

    xStart = 0;
    yStart = 15;
    xGoal=n*2/3;
    yGoal=m/5;

    xPlayer = xStart;
    yPlayer = yStart;
    
    xTF1 = n/3;
    yTF1 = 50;

    xTF2 = n-1;
    yTF2 = m-1;


    
    std::thread interfaceThread(interfaz);
   	interfaceThread.detach();

	std::thread functionThread(function_ );
    functionThread.join();

    while ( !((xPlayer==xGoal)&&(yPlayer==yGoal))){
    	;
    }

   

    std::cout<<"Start: "<< xPlayer <<","<<yPlayer<<std::endl;
    std::cout<<"Finish: "<< xGoal <<","<<yGoal<<std::endl;
    

    getchar(); // wait for a (Enter) keypress  
    return(0);
}

void changearoundA( int x , int y){
	map[x][y]=5;
	if (map[x-1][y]==0)
		map[x-1][y]=5;
	if (map[x+1][y]==0)
		map[x+1][y]=5;
	if (map[x][y-1]==0)
		map[x][y-1]=5;
	if (map[x][y+1]==0)
		map[x][y+1]=5;
}

void changearoundB( int x , int y){
	map[x][y]=0;
	if (map[x-1][y]==5)
		map[x-1][y]=0;
	if (map[x+1][y]==5)
		map[x+1][y]=0;
	if (map[x][y-1]==5)
		map[x][y-1]=0;
	if (map[x][y+1]==5)
		map[x][y+1]=0;
}



void setMet2(){
	srand(time(NULL));
	for( int x=0 ; x<num_met ; ++x){
		xMet[x] = (rand()%10)+45;
		yMet[x] = (rand()%5)+1;
	}
}

void function_(){

	int gameclock =0 ;
	
    int j; char c;
    
    setMet2();

	while ( !((xPlayer==xGoal)&&(yPlayer==yGoal))){

		

		std::cout<<"Current: "<< xPlayer <<","<<yPlayer<<std::endl;

	
		changearoundA(xTF1 , yTF1);
		changearoundA(xTF2 , yTF2);
		for( int x=0 ; x<num_met ; ++x){
			changearoundA(xMet[x] , yMet[x]);
		}

        route=pathFind(xPlayer, yPlayer, xGoal, yGoal);

        for( int x=0 ; x<num_met ; ++x){
			changearoundB(xMet[x] , yMet[x]);
		}
        changearoundB(xTF1 , yTF1);
		changearoundB(xTF2 , yTF2);


        std::cout<<"Route:"<<std::endl;
        std::cout<<route<<std::endl;
        c = route.at(0);
        j=atoi(&c);
        xPlayer=xPlayer+dx[j];
        yPlayer=yPlayer+dy[j];

        
        if (gameclock%3!=0){
        	route1=pathFind(xTF1, yTF1, xPlayer, yPlayer);
	        c = route1.at(0);
	        j=atoi(&c);
	        xTF1=xTF1+dx[j];
	        yTF1=yTF1+dy[j];
	    }

	    if (gameclock%5!=0){
        	route1=pathFind(xTF2, yTF2, xPlayer, yPlayer);
	        c = route1.at(0);
	        j=atoi(&c);
	        xTF2=xTF2+dx[j];
	        yTF2=yTF2+dy[j];
	    }


	    if (gameclock%2!=0){
        	for( int x=0 ; x<num_met ; ++x){
        		if (xMet[x] < 0){
        			xMet[x] = 55; //(rand()%30)+25;
					yMet[x] = (rand()%50)+5;
				}
				xMet[x] = xMet[x] -1;
				//yMet[x] = xMet[x] -1;
			}
			       	
	    }


        ++gameclock;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }


}