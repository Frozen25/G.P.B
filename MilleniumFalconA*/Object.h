struct Object {
	int x, y,code;

	Shape(int _x, int _y){
		x =_x;
		y =_y;
	}

	virtual void update(){}
	virtual void draw() {}
};