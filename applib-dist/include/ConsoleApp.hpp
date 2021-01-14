/*
File:ConsoleApp.hpp
Autor: Chunhui Ma
Content: a console interface
Date: March 23, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#pragma once
#include <App.hpp>
#include "Console.hpp"
#include <memory>
class ConsoleApp :public App {

protected:
	std::shared_ptr<Console> console;

protected:
	ConsoleApp();
};