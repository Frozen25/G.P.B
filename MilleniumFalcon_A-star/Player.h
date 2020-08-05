
#include "vars.h"

struct Player : Object {
	code = 7;

	

	void update(int xGoal, int yGoal){
		int j; char c; string route;
		route=pathFind( x, y , xGoal, yGoal);
        c = route.at(0);
        j=atoi(&c);

        map[yPlayer][xPlayer]=0;
        xPlayer=xPlayer+dx[j];
        yPlayer=yPlayer+dy[j];
        map[yPlayer][xPlayer]=7;
        
	}
	void draw() {

	}
};