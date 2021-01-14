#pragma once

/*
File: WinAPIWrapper.hpp
Autor: Chunhui Ma
Content: WinApiWrapper : thin wraper
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
#include "Event.hpp"

//bool cPress = false;



class WinAPIWrapper {

public:

	using ScreenBufferInfo = CONSOLE_SCREEN_BUFFER_INFO;
	using CursorInfo = CONSOLE_CURSOR_INFO;
	using Rectangle = SMALL_RECT;
	using vectorOfCharInfo = std::vector<CHAR_INFO>;
	using Coord = COORD;
	using color = WORD;
	using Small_Number = short;

	static bool cPressed;

	color White;
	color Red;
	color Green;
	color Blue;
	color Yellow;
	color YellowBack;
	color MilkYellowBack;
	color GreenBack;
	color WhiteBack;
	color Black;


private:
	HANDLE hStdin;
	HANDLE hStdout;
	HANDLE hConsoleInput, hConsoleOutput;

public:

	//contructor
	WinAPIWrapper();

	/*
	Method Name: setCursor
	Purpose: set the Cursor info
	Parameter: CursorInfo
	Return: void 
	*/
	void setCursor(CursorInfo& info);

	/*
	Method Name:setCursorPosition
	Purpose: set the Curser positon
	Parameter: ScreenBufferInfo
	Return: void 
	*/
	void setCursorPosition(ScreenBufferInfo screenBufferInfo);

	/*
	Method Name:SaveDesktop
	Purpose: save desktop
	Parameter: vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord
	Return: Rectangle
	*/
	Rectangle SaveDesktop(vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord);

	/*
	Method Name:setDesktop
	Purpose: set the desktop
	Parameter: vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord, Rectangle& bufferRectangle
	Return: void 
	*/
	void setDesktop(vectorOfCharInfo& Buffer, ScreenBufferInfo& screenBufferInfo, Coord& BufferCoord, Rectangle& bufferRectangle);

	/*
	Method Name:getScreenBufferInfo
	Purpose: get Screen Buffer Infomaiton
	Parameter: none
	Return:ScreenBufferInfo
	*/
	ScreenBufferInfo getScreenBufferInfo();

	/*
	Method Name:getCursorInfo
	Purpose: get the cursor information
	Parameter: none
	Return:CursorInfo
	*/
	CursorInfo getCursorInfo();

	/*
	Method Name:getWindowWidth
	Purpose: get the window width
	Parameter: none
	Return: Small_Number
	*/
	Small_Number getWindowWidth();

	/*
	Method Name:getWindowHeight
	Purpose: get the window Height
	Parameter: none
	Return: Small_Number
	*/
	Small_Number getWindowHeight();

	/*
	Method Name:resizeWindow
	Purpose: Resize the window
	Parameter: 2 Small_Number
	Return: Small_Number
	*/
	Small_Number resizeWindow(Small_Number width, Small_Number height);

	/*
	Method Name:getTitle
	Purpose: get the Title
	Parameter: none
	Return: string
	*/
	std::string getTitle();

	/*
	Method Name:SetTitle
	Purpose: set title
	Parameter: string
	Return: void
	*/
	void SetTitle(std::string title);

	/*
	Method Name:HideTheCursor
	Purpose: HideTheCursor 
	Parameter: CursorInfo
	Return: void
	*/
	void HideTheCursor(CursorInfo originalCCI);

	/*
	Method Name:Print
	Purpose: Print some thing to screen
	Parameter: string msg, int x, int y, color textColor, color backgroud
	Return:none
	*/
	void Print(std::string msg, int x, int y, color textColor, color backgroud);

	/*
	Method Name:GetEvents
	Purpose: GetEvents
	Parameter: none
	Return: vector<Event>
	*/
	std::vector<Event> GetEvents();


private:
	/*
	Method Name:EventGenerator
	Purpose: Generate a event
	Parameter: MOUSE_EVENT_RECORD
	Return: event
	*/
	Event EventGenerator(MOUSE_EVENT_RECORD const& mer);


};