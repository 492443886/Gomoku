
/*
File: XError.hpp
Autor: Chunhui Ma
Content: Method body of XError
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#include <XError.hpp>
using namespace std;


string ErrorDescription(DWORD dwMessageID) {
	char* msg;
	auto c = FormatMessageA(
		/* flags */			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_MAX_WIDTH_MASK,
		/* source*/			NULL,
		/* message ID */	dwMessageID,
		/* language */		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		/* buffer */		(LPSTR)&msg,
		/* size */			0,
		/* args */			NULL
	);

	string strMsg = (c == 0)
		? "unknown"
		: msg;
	LocalFree(msg);
	return strMsg;
}


XError::string_type XError::msg() const {
	ostringstream oss;
	oss << "Error: " << code() << "\n";
	oss << ErrorDescription(code()) << "\n";
	oss << "In: " << file() << "\n";
	oss << "Line: " << line() << "\n";
	return oss.str();
}

XError::XError(int line, file_type file) : code_(GetLastError()), line_(line), file_(file) {}