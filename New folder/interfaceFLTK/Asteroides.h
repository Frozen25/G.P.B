#ifndef POINT_H
#define POINT_H


#include "../common.h"
#include "Circle.h"
#include "Windows.h"

class Asteroides {
	

	public:
		int x , y;
		Circle circ;

		Asteroides();
		Asteroides(int _x , int _y);
		void update(int n);
		void draw(Windows* window) ;
};