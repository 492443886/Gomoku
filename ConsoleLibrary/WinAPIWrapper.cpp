
/*
File: WinApiWrapper.cpp
Autor: Chunhui Ma
Content: method body of WinAPIWrapper.cpp
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <WinAPIWrapper.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <XError.hpp>
#include <Event.hpp>
using namespace std;

bool WinAPIWrapper::cPressed = false;


BOOL CtrlHandler(DWORD ctrlType) {
	switch (ctrlType) {
	case CTRL_C_EVENT:

		WinAPIWrapper::cPressed = true;
		return TRUE;
	}

	return FALSE;
}

WinAPIWrapper::WinAPIWrapper() {
	try {


		hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		hStdin = GetStdHandle(STD_INPUT_HANDLE);
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		//cPressed = false;


		if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE)) {

		}
		else {
			cerr << "ERROR: failed to install control handler." << endl;

		}

		Black				= 0;
		Red					= FOREGROUND_RED;
		White				= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		Green				= FOREGROUND_GREEN;
		Blue				= FOREGROUND_BLUE;
		Yellow				= FOREGROUND_RED | FOREGROUND_GREEN;
		WhiteBack           = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED;
		YellowBack          = BACKGROUND_RED | BACKGROUND_GREEN;
		MilkYellowBack		= BACKGROUND_RED | BACKGROUND_GREEN|BACKGROUND_INTENSITY;
		GreenBack			= BACKGROUND_GREEN;

	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
}


void WinAPIWrapper::setCursor(WinAPIWrapper::CursorInfo& info) {
	try {
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorInfo(hConsoleOutput, &info));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
}

void WinAPIWrapper::setCursorPosition(ScreenBufferInfo screenBufferInfo) {

	try {
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorPosition(hConsoleOutput, screenBufferInfo.dwCursorPosition));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
}


WinAPIWrapper::Rectangle  WinAPIWrapper::SaveDesktop(vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord) {
	SMALL_RECT bufferRect{ 0 };
	try {
		// Save the desktop
		Buffer.resize(screenBufferInfo.dwSize.X*screenBufferInfo.dwSize.Y);
		BufferCoord = COORD{ 0 };
		
		bufferRect.Right = screenBufferInfo.dwSize.X - 1;
		bufferRect.Bottom = screenBufferInfo.dwSize.Y - 1;
		THROW_IF_CONSOLE_ERROR(ReadConsoleOutputA(hConsoleOutput, Buffer.data(), screenBufferInfo.dwSize, BufferCoord, &bufferRect));

		
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
	return bufferRect;

}

void WinAPIWrapper::setDesktop(vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord, Rectangle& bufferRectangle) {
	try {

		SMALL_RECT sr{ 0 };
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));
		THROW_IF_CONSOLE_ERROR(SetConsoleScreenBufferSize(hConsoleOutput, screenBufferInfo.dwSize));
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &screenBufferInfo.srWindow));


		bufferRectangle = SMALL_RECT{ 0 };
		bufferRectangle.Right = screenBufferInfo.dwSize.X - 1;
		bufferRectangle.Bottom = screenBufferInfo.dwSize.Y - 1;
		THROW_IF_CONSOLE_ERROR(WriteConsoleOutputA(hConsoleOutput, Buffer.data(), screenBufferInfo.dwSize, BufferCoord, &bufferRectangle));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}

}


WinAPIWrapper::ScreenBufferInfo WinAPIWrapper::getScreenBufferInfo() {
	ScreenBufferInfo Original;
	try {
		
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &Original));

	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
		
	}

	return Original;
}

WinAPIWrapper::CursorInfo WinAPIWrapper::getCursorInfo() {
	
	CursorInfo info;
	try {
		
		THROW_IF_CONSOLE_ERROR(GetConsoleCursorInfo(hConsoleOutput, &info));
		
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
	return info;
}

WinAPIWrapper::Small_Number WinAPIWrapper::getWindowWidth() {

	ScreenBufferInfo consoleInfo;
	try {
		
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &consoleInfo));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}
	return consoleInfo.dwSize.X;

}


WinAPIWrapper::Small_Number WinAPIWrapper::getWindowHeight() {

	ScreenBufferInfo consoleInfo;

	try {
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &consoleInfo));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
	}

	return consoleInfo.dwSize.Y;
}

WinAPIWrapper::Small_Number  WinAPIWrapper::resizeWindow(WinAPIWrapper::Small_Number width, WinAPIWrapper::Small_Number height) {

	try{
		SMALL_RECT sr{ 0 };
		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));

		COORD bufferSize;
		bufferSize.X = width;
		bufferSize.Y = height;
		THROW_IF_CONSOLE_ERROR(SetConsoleScreenBufferSize(hConsoleOutput, bufferSize));

		CONSOLE_SCREEN_BUFFER_INFO sbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &sbi));

		sr.Top = sr.Left = 0;
		width = min((SHORT)width, sbi.dwMaximumWindowSize.X);
		height = min((SHORT)height, sbi.dwMaximumWindowSize.Y);
		sr.Right = width - 1;
		sr.Bottom = height - 1;

		THROW_IF_CONSOLE_ERROR(SetConsoleWindowInfo(hConsoleOutput, TRUE, &sr));
		return sr.Right - sr.Left + 1;
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);
		return -1;
	}
}

string WinAPIWrapper::getTitle() {
	
	vector<char> originalTitle(64 * 1024);

	try {
		originalTitle.resize(GetConsoleTitleA(originalTitle.data(), (DWORD)originalTitle.size()) + 1);
		originalTitle.shrink_to_fit();
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
	return originalTitle.data();
}

void WinAPIWrapper::SetTitle(string title) {


	try {
		SetConsoleTitleA(title.c_str());
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
}

void WinAPIWrapper::HideTheCursor(CursorInfo originalCCI) {
	try {
		auto newCCI = originalCCI;
		newCCI.bVisible = FALSE;
		THROW_IF_CONSOLE_ERROR(SetConsoleCursorInfo(hConsoleOutput, &newCCI));
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
}


void WinAPIWrapper::Print(string msg, int x, int y, color textColor , color backgroud) {


	try {
		// Get the number of character cells in the current buffer
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		THROW_IF_CONSOLE_ERROR(GetConsoleScreenBufferInfo(hConsoleOutput, &csbi));

		vector<WORD> attr;
		auto le = msg.length();
		for (size_t i = 0; i < le; i++)
			attr.push_back(textColor | backgroud);
		COORD loc;
		loc.X = (WinAPIWrapper::Small_Number)x;
		loc.Y = (WinAPIWrapper::Small_Number)y;
		DWORD nCharsWritten;

		WriteConsoleOutputCharacterA(hConsoleOutput, msg.c_str(), (DWORD)msg.size(), loc, &nCharsWritten);
		WriteConsoleOutputAttribute(hConsoleOutput, attr.data(), (DWORD)attr.size(), loc, &nCharsWritten);
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
}

Event ProcessKeyEvent(KEY_EVENT_RECORD const& ker) {
	
	try {
		string upDown = (ker.bKeyDown ? "KP" : "KR");
		if (ker.wVirtualKeyCode == 32) {
			Event e("Restart", 0, 0);
			return e;
		}
		string c = "";
		if (isgraph(ker.uChar.AsciiChar))
			c = ker.uChar.AsciiChar;

		if (c == "q" && upDown == "KR") {
			Event e("q", 0, 0);
			return e;
		}
		if (c == "w" && upDown == "KR") {
			Event e("w", 0, 0);
			return e;
		}
		if (c == "e" && upDown == "KR") {
			Event e("e", 0, 0);
			return e;
		}
		if (c == "r" && upDown == "KR") {
			Event e("r", 0, 0);
			return e;
		}
		if (c == "t" && upDown == "KR") {
			Event e("t", 0, 0);
			return e;
		}
		if (c == "y" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "u" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "i" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "o" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "p" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "a" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "s" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "d" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}


		if (c == "f" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "g" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "h" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}


		if (c == "j" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}

		if (c == "k" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "l" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "z" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "x" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "c" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "v" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "b" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "n" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}
		if (c == "m" && upDown == "KR") {
			Event e(c, 0, 0);
			return e;
		}





	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
	Event e("", 0, 0);
	return e;


}


vector<Event> WinAPIWrapper::GetEvents() {
	
	std::vector<Event> Events;
	try {
		std::vector<INPUT_RECORD> inBuffer(128);
		

		DWORD numEvents;
		if (!ReadConsoleInput(hStdin, inBuffer.data(), (DWORD)inBuffer.size(), &numEvents)) {
			std::cerr << "Failed to read console input\n";

			return Events;
		}


		for (size_t iEvent = 0; iEvent < numEvents; ++iEvent) {

			switch (inBuffer[iEvent].EventType) {
			case MOUSE_EVENT: {
				Events.push_back(EventGenerator(inBuffer[iEvent].Event.MouseEvent));
			}
			case KEY_EVENT:
				Events.push_back(ProcessKeyEvent(inBuffer[iEvent].Event.KeyEvent));
				break;

			}

		}
		
	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
	return Events;
}

Event WinAPIWrapper::EventGenerator(MOUSE_EVENT_RECORD const& mer) {
	try{
		auto bufferLoc = mer.dwMousePosition;
		switch (mer.dwEventFlags) {
		case 0: // button pressed or released
		{
			auto mask = mer.dwButtonState;
			if (mask&FROM_LEFT_1ST_BUTTON_PRESSED) {

				Event e("Left", bufferLoc.X, bufferLoc.Y);
				return e;
			}
			if (mask&RIGHTMOST_BUTTON_PRESSED) {

				Event e("Right", bufferLoc.X, bufferLoc.Y);
				return e;
			}

		}break;

		default:

			Event e("", 0, 0);
			return e;
			break;
		}

	}
	catch (XError& e) {
		MessageBoxA(NULL, e.msg().c_str(), "Runtime Error", MB_OK);

	}
	Event e("", 0, 0);
	return e;
}

