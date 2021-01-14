#pragma once
/*
File: Event.hpp
Autor: Chunhui Ma
Content: a Event object used to be used as a event
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/


#include <string>

class Event {

public:
	std::string EventName;
	int x;
	int y;

	//constructor
	Event(std::string name, int x, int y);
};