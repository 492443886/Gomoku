#include <string>
#include "WinAPIWrapper.hpp"
#include "Console.hpp"
#include <memory>
#pragma once
/*
File: ConsoleAdapter.hpp
Autor: Chunhui Ma
Content: ConsoleAdapter: thick wrapper
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/


class ConsoleAdapter: public Console {

public:


private:
	WinAPIWrapper::CursorInfo			originalCCI;
	WinAPIWrapper::ScreenBufferInfo		originalCSBI;
	
	WinAPIWrapper::vectorOfCharInfo		originalBuffer;
	WinAPIWrapper::Coord				originalBufferCoord;
	WinAPIWrapper::Rectangle			bufferRect;
	WinAPIWrapper::Small_Number			currentConsoleWidth = 0;

	WinAPIWrapper::Small_Number OriginalWidth;
	WinAPIWrapper::Small_Number OriginalHeight;
	std::string originalTitle;
	
	std::shared_ptr<WinAPIWrapper> APIWraper;


public:
	

	// constructure
	ConsoleAdapter();


	/*
	Method Name: StoreState
	Purpose: Store the state of
	Parameter: none
	Return:void
	*/
	void StoreState();

	/*
	Method Name: restoreState
	Purpose: restore the state fo console
	Parameter: nonne
	Return: void
	*/
	void restoreState();

	/*
	Method Name: HideCursor
	Purpose: Hide the cursor on the console
	Parameter:none
	Return: void
	*/
	void HideCursor();

	/*
	Method Name: geteEvent
	Purpose: Get the events
	Parameter: none
	Return:vector<Event>
	*/
	std::vector<Event> getEvents();

	/*
	Method Name: SetTitle
	Purpose: set the title for the console
	Parameter: string
	Return: void
	*/
	void SetTitle(std::string s);

	/*
	Method Name: resizeWindow
	Purpose: Resize the Window
	Parameter: int x , int y
	Return: void
	*/
	void resizeWindow(int x, int y);
	
	/*
	Method Name: Print
	Purpose: the print thing on console`
	Parameter: string msg, int x, int y, string fontColor, string backColor
	Return: void
	*/
	void Print(std::string msg, int x, int y, std::string fontColor, std::string backColor);
};