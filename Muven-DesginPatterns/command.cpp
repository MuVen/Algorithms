// command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	commands should always take receiver object & receiver method in the ctor.
*/

class light;
class command{
public:
	virtual void execute() = 0;
};

class lightOffCommand : public command{
	light* m_ptr;
	void (light::*m_method)();
public:
	lightOffCommand(light* a_ptr, void (light::*a_method)() = 0):m_ptr(a_ptr),m_method(a_method) {}
	void execute(){
		(m_ptr->*m_method)();
	}
};

class lightOnCommand : public command{
	light* m_ptr;
	void (light::*m_method)();
public:
	lightOnCommand(light* a_ptr, void (light::*a_method)() = 0):m_ptr(a_ptr),m_method(a_method) {}
	void execute(){
		(m_ptr->*m_method)();
	}
};

class light{
public:
	void lightOff(){
		cout<<"Light Off\n";
	}
	void lightOn(){
		cout<<"Light On\n";
	}
};

class remoteControl{
	command* cmd;
public:
	void setCommand(command* m_cmd){
		cmd = m_cmd;
	}
	void buttonPressed(){
		cmd->execute();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	light l;

	lightOnCommand loc(&l, &light::lightOn);
	lightOffCommand lofc(&l, &light::lightOff);

	remoteControl rc;
	rc.setCommand(&loc);
	rc.buttonPressed();

	rc.setCommand(&lofc);
	rc.buttonPressed();

	return 0;
}

