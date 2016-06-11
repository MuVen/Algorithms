// private_class_data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	A class may expose its attributes (class variables) to manipulation
	when manipulation is no longer desirable, e.g. after construction. Using
	the private class data design pattern prevents that undesirable
	manipulation.

	A class may have one-time mutable attributes that cannot be
	declared final. Using this design pattern allows one-time setting of those
	class attributes.
*/

class CircleData{
	double radius;
	int originX;
	int originY;
public:
	CircleData(){}
	CircleData(double a_radius, int a_originX, int a_originY) :
	   radius(a_radius),
	   originX(a_originX),
	   originY(a_originY){}
  
	  double getRadius(){ return radius;}
	  int getOriginX(){ return originX;}
	  int getOriginY(){ return originY;}
};

class Circle : private CircleData{
	CircleData* m_cd;
public:
	Circle(double radius, int oX, int oY){
		m_cd = new CircleData(radius, oX, oY);	
	}

	~Circle(){
		delete m_cd;
	}

    double Circumference(){
       return 2 * (3.14285714) * m_cd->getRadius();
    }

    double Diameter(){
	    return 2 * m_cd->getRadius();
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Circle c(14.000, 5, 5);
	cout<<c.Circumference()<<endl;
	cout<<c.Diameter()<<endl;
	return 0;
}

