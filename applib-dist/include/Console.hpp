#pragma once
#include <vector>
#include <Event.hpp>
/*
File:Console.hpp
Autor: Chunhui Ma
Content: a console interface
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/


class Console {

public:

	/*
	Method Name: StoreState
	Purpose: Store the state of 
	Parameter: none
	Return:void
	*/
	virtual void StoreState()  =0;

	/*
	Method Name: restoreState
	Purpose: restore the state fo console
	Parameter: nonne
	Return: void 
	*/
	virtual void restoreState()	=0;

	/*
	Method Name: HideCursor
	Purpose: Hide the cursor on the console
	Parameter:none
	Return: void
	*/
	virtual void HideCursor()=0;

	/*
	Method Name: geteEvent
	Purpose: Get the events
	Parameter: none
	Return:vector<Event>
	*/
	virtual std::vector<Event> getEvents()=0;

	/*
	Method Name: SetTitle
	Purpose: set the title for the console
	Parameter: string
	Return: void
	*/
	virtual void SetTitle(std::string s)  =0;

	/*
	Method Name: resizeWindow
	Purpose: Resize the Window
	Parameter: int x , int y
	Return: void 
	*/
	virtual void resizeWindow(int x, int y) =0;

	/*
	Method Name: Print
	Purpose: the print thing on console`		
	Parameter: string msg, int x, int y, string fontColor, string backColor
	Return: void 
	*/
	virtual void Print(std::string msg, int x, int y, std::string fontColor, std::string backColor)=0;

};