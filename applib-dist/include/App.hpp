
/*
File:app.hpp
Autor: Chunhui Ma
Content: a console interface
Date: March 23, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#pragma once
#include <string>
#include <vector>
#include <memory>



#if defined(_DEBUG) && defined(_DLL)
#pragma comment (lib, "applib-mt-gd.lib")
#elif defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib, "applib-mt-sgd.lib")
#elif !defined(_DEBUG) && defined(_DLL)
#pragma comment (lib, "applib-mt.lib")
#elif !defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib, "applib-mt-s.lib")
#endif


class App {
	using Args = std::vector<std::string>;
	Args _args;
	static App* thisApp;
	friend int main(int argc, char* argv[]);
	static int main(int argc, char* argv[]);
protected:
	App();
	virtual ~App() = default;
	/*
	Method Name: execute
	Purpose: This method is for exacute app
	Parameter: none
	Return:void
	*/
	virtual int execute() = 0;
	/*
	Method Name: QueryArgs
	Purpose: This method is for commend line args
	Parameter: none
	Return:void
	*/
	Args const& QueryArgs() const { return _args; }
};