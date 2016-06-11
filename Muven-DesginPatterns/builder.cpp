// builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class airplane{
	char bodyName[100];
	char wingName[100];
public:
	void setBodyName(char* bName){
		strcpy(bodyName, bName);
	}

	char* getBodyName(){
		return bodyName;
	}

	void setWingName(char* wName){
		strcpy(wingName, wName);
	}

	char* getWingName(){
		return wingName;
	}
};

class airplaneBuilder{
public:
	virtual void BuildBody() = 0;
	virtual void BuildWings() = 0;
	virtual airplane* BuiltProduct() = 0;
};

class Director {
public:
	airplane* buildAirplane(airplaneBuilder* apm) {
		apm->BuildBody();
		apm->BuildWings();
		return apm->BuiltProduct();
	}
};

class JetBuilder : public airplaneBuilder {
	airplane* jetplane;
public:
	JetBuilder(){
		jetplane = new airplane;
	}
	void BuildBody(){
		jetplane->setBodyName("Metal Body");
	}
	void BuildWings(){
		jetplane->setWingName("Metal Wing");
	}
	airplane* BuiltProduct(){
		return jetplane;
	}

};

class WindBuilder: public airplaneBuilder {
	airplane* windplane;
public:
	WindBuilder(){
		windplane = new airplane;
	}
	void BuildBody(){
		windplane->setBodyName("Wood Body");
	}
	void BuildWings(){
		windplane->setWingName("Wood Wing");
	}
    airplane* BuiltProduct(){
		return windplane;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Director* d = new Director();
	airplane* jPlane = d->buildAirplane(new JetBuilder);
	cout<<"JetPlane: "<<jPlane->getBodyName()<<" "<<jPlane->getWingName()<<endl;
	airplane* wPlane = d->buildAirplane(new WindBuilder);
	cout<<"WindPlane: "<<wPlane->getBodyName()<<" "<<wPlane->getWingName()<<endl;
}