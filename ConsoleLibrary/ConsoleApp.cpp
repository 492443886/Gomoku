
/*
File: ConsoleApp.cpp
Autor: Chunhui Ma
Content: method body of ConsoleAdapter
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <ConsoleApp.hpp>
#include <ConsoleAdapter.hpp>
ConsoleApp::ConsoleApp() {

	console = std::make_shared<ConsoleAdapter>();
}