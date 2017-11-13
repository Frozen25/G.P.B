#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "recipe.h"
#include "common.h"


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
    
    


    int xStart = 0;
    int yStart = 15;
    int xGoal=n*1/3;
    int yGoal=m/5;

    int xPlayer = xStart;
    int yPlayer = yStart;
    

    string route="";
    int j; char c;
    int i=0;
    //route=pathFind(xPlayer, yPlayer, xGoal, yGoal);
    while ( !((xPlayer==xGoal) &&(yPlayer==yGoal))){//(route.length()>1)){
        route=pathFind(xPlayer, yPlayer, xGoal, yGoal);
        std::cout<<"Route:"<<std::endl;
        std::cout<<route<<std::endl;
        c = route.at(i);
        j=atoi(&c);
        xPlayer=xPlayer+dx[j];
        yPlayer=yPlayer+dy[j];
        

    }
    std::cout<<"Start: "<< xPlayer <<","<<yPlayer<<std::endl;
    std::cout<<"Finish: "<< xGoal <<","<<yGoal<<std::endl;
    
    //route=pathFind(xA, yA, xB, yB);
    //c = route.at(i);
    //j=atoi(&c);
    //xA=xA+dx[j];
    //yA=yA+dy[j];
    //std::cout<<"Route:"<<std::endl;
    //std::cout<<route<<std::endl;


    /*
    std::cout<<"Map Size (X,Y): "<<n<<","<<m<<std::endl;
    std::cout<<"Start: "<< xA <<","<<yA<<std::endl;
    std::cout<<"Finish: "<< xB <<","<<yB<<std::endl;
    // get the route
    clock_t start = clock();
    //string route=pathFind(xA, yA, xB, yB);
    if(route=="") std::cout<<"An empty route generated!"<<std::endl;
    clock_t end = clock();
    double time_elapsed = double(end - start);
    std::cout<<"Time to calculate the route (ms): "<<time_elapsed<<std::endl;
    std::cout<<"Route:"<<std::endl;
    std::cout<<route<<std::endl<<std::endl;

    // follow the route on the map and display it 
    if(route.length()>0)
    {
        int j; char c;
        int x=xA;
        int y=yA;
        map[x][y]=2;
        for(int i=0;i<route.length();i++)
        {
            c =route.at(i);
            j=atoi(&c); 
            x=x+dx[j];
            y=y+dy[j];
            map[x][y]=3;
        }
        map[x][y]=4;
    
        // display the map with the route
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(map[x][y]==0)
                    std::cout<<".";
                else if(map[x][y]==1)
                    std::cout<<"O"; //obstacle
                else if(map[x][y]==2)
                    std::cout<<"S"; //start
                else if(map[x][y]==3)
                    std::cout<<"R"; //route
                else if(map[x][y]==4)
                    std::cout<<"F"; //finish
            std::cout<<std::endl;
        }
    }
    */
    getchar(); // wait for a (Enter) keypress  
    return(0);
}