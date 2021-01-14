#pragma once

/*
File: View.hpp
Autor: Chunhui Ma
Content: a View object used to be used as a View
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <Console.hpp>
#include "Command.hpp"
#include <memory>
class View {
public: 
	virtual void update() = 0;
	virtual bool isHit(Event event) = 0;
	virtual std::shared_ptr<Command> EventPush(Event e) = 0;
	
};
