#include "Asteroides.h"

Asteroides::Asteroides(){}

Asteroides::Asteroides(int _x , int _y){
	x= _x;
	y= _y;
	circ = Circle(Point(x*10+5,y*10+5),10,1,FL_RED,FL_RED);
}

void Asteroides::update(int n){
	x = xMet[n];
	y = yMet[n];
	circ = Circle(Point(x*10+5,y*10+5),10,1,FL_RED,FL_RED);
}
void Asteroides::draw(Windows* window) {
	window->attach(circ);

}
