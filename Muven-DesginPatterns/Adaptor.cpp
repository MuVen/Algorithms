// Adaptor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Rectangle{
public:
	virtual void draw() = 0;
};

class OldRectangle{
	int x1, y1, w1, h1;
public:
	OldRectangle(int x, int y, int w, int h):x1(x),y1(y),w1(w),h1(h){ }
	void oldDraw(){
		cout<<x1<<" "<<y1<<" "<<w1<<" "<<h1;
	}
};

class RectangleAdaptor: public Rectangle, private OldRectangle{
public:
	RectangleAdaptor(int x, int y, int w, int h):OldRectangle(x,y,w,h){}
	void draw(){
		cout<<"Rectangle Adaptor Draw()"<<endl;
		oldDraw();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle* rect = new RectangleAdaptor(10, 10, 50, 50);
	rect->draw();
}

