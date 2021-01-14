/*
File: App.cpp
Autor: Chunhui Ma
Content: method body of ConsoleAdapter
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
//#define _CRT_DEBUG_MAP_ALLOC
//#include <crtdbg.h>		// C Run Time Debug library
//



#include <App.hpp>
#include <cassert>
#include <iostream>
App* App::thisApp = nullptr;

App::App() {
	assert(!thisApp && "Error: Already initialized!");
	thisApp = this;
}

int App::main(int argc, char*argv[]) {
	for (int i = 1; i < argc; ++i)
		thisApp->_args.push_back(argv[i]);
	return thisApp->execute();
}

int main(int argc, char*argv[]) try {
	return App::main(argc, argv);
}
catch (char const* msg) {
	std::cerr << "Caught string: " << msg << std::endl;
	return EXIT_FAILURE;
}
catch (std::exception const& e) {
	std::cerr << "Caught std::exception: " << e.what() << std::endl;
	return EXIT_FAILURE;
}
catch (...) {
	std::cerr << "Error: an unknown exception has been caught.\n";
	return EXIT_FAILURE;
}