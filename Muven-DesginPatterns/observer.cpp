// observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
using namespace std;

class NumaratorSubject{
	vector<class Observer *> views;
	int numo;
public:
	void attach(Observer *obs){
		views.push_back(obs);
	}
	void setNumarator(int a_numo){
	    numo = a_numo;
		notify();
	}
	int getNumarator(){
		return numo;
	}
	void notify();
};


class Observer{
	NumaratorSubject *model;
	int deno;
public:
	Observer(NumaratorSubject* a_model, int a_deno){
		model = a_model;
		deno = a_deno;

		model->attach(this);
	}
	virtual void update() = 0;
protected:
	NumaratorSubject *getNSubject(){
		return model;
	}
	int getDenominator(){
		return deno;
	}
};

void NumaratorSubject::notify(){
	for(unsigned int i = 0; i < views.size(); i++)
		views[i]->update();
}

class DivObserver: public Observer{
public:
	DivObserver(NumaratorSubject *a_model, int a_deno):Observer(a_model,a_deno){}
	void update(){
		cout<<"Updated Div Result As Numarator Updated : "<<((getNSubject()->getNumarator())/(getDenominator()))<<endl;
	}
};

class ModObserver: public Observer{
public:
	ModObserver(NumaratorSubject *a_model, int a_deno):Observer(a_model,a_deno){}
	void update(){
		cout<<"Updated Mod Result As Numarator Updated : "<<((getNSubject()->getNumarator())%(getDenominator()))<<endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	NumaratorSubject ns;

	DivObserver dob(&ns, 6);
	ModObserver mob(&ns, 6);

	ns.setNumarator(89);
}

