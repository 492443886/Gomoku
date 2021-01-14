#pragma once

/*
File: XError.hpp 
Autor: Chunhui Ma
Content: a Class used to handle the exception
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/


#include <Windows.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


/* ErrorDescription */
std::string ErrorDescription(DWORD dwMessageID);


/* Console error exception class. */
class XError {
public:
	using id_type = decltype(GetLastError());
	using file_type = char const *;
	using string_type = std::string;
private:
	id_type code_;
	int	line_;
	file_type file_;
public:
	XError(int line, file_type file);
	inline auto code() const -> id_type { return code_; }
	inline auto line() const -> int { return line_; }
	inline auto file() const -> file_type { return file_; }


	/*
	Method Name:msg
	Purpose: get the error message
	Parameter: none
	Return:string type
	*/


	string_type msg() const;
};



/* Console error exception throw helper macro. */
#define THROW_IF_CONSOLE_ERROR(res) if(!res) throw XError(__LINE__,__FILE__)
#define THROW_CONSOLE_ERROR() throw XError(__LINE__,__FILE__)
