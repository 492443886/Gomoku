
/*
File: ConsoelAdapter.cpp
Autor: Chunhui Ma
Content: method body of ConsoleAdapter 
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/


#include <ConsoleAdapter.hpp>
#include <memory>
#include <Event.hpp>
#include <iostream>
using namespace std;

ConsoleAdapter::ConsoleAdapter() {
	APIWraper = make_shared<WinAPIWrapper>();
}

//ConsoleAdapter::~ConsoleAdapter() {
//	//delete[] APIWraper;
//}

void ConsoleAdapter::StoreState() {

	originalTitle = APIWraper->getTitle();

	// Get the old window/buffer size
	originalCSBI = APIWraper->getScreenBufferInfo();

	OriginalWidth = APIWraper->getWindowWidth();
	OriginalHeight = APIWraper->getWindowHeight();

	WinAPIWrapper::Rectangle bufferRect = APIWraper->SaveDesktop(originalBuffer, originalCSBI, originalBufferCoord);
	// Save the cursor
	originalCCI = APIWraper->getCursorInfo();

	bufferRect = APIWraper->SaveDesktop(originalBuffer, originalCSBI, originalBufferCoord);
}



void ConsoleAdapter::restoreState() {
	//APIWraper->resizeWindow(OriginalWidth, OriginalHeight);

	APIWraper->setDesktop(originalBuffer, originalCSBI, originalBufferCoord, bufferRect);

	APIWraper->SetTitle(originalTitle.data());

	// Restore the cursor
	APIWraper->setCursor(originalCCI);
	APIWraper->setCursorPosition(originalCSBI);
}



void ConsoleAdapter::ConsoleAdapter::HideCursor() {
	APIWraper->HideTheCursor(originalCCI);
}


std::vector<Event> ConsoleAdapter::getEvents() {

	if (WinAPIWrapper::cPressed == true) {
		auto events = APIWraper->GetEvents();
		Event e("cPressed", 0, 0);
		events.push_back(e);

		return events;
	}
	return APIWraper->GetEvents();
}

void ConsoleAdapter::SetTitle(std::string s) {
	APIWraper->SetTitle(s);
}

void ConsoleAdapter::resizeWindow(int x, int y) {


	APIWraper->resizeWindow(x, y);
}

void ConsoleAdapter::Print(std::string msg, int x, int y, std::string fontColor, std::string backColor) {
	auto Forcolor = APIWraper->White;
	auto Backcolor = APIWraper->YellowBack;
	if (fontColor == "Green") {
		Forcolor = APIWraper->Green;
	}
	if (fontColor == "Blue") {
		Forcolor = APIWraper->Blue;
	}

	if (fontColor == "Black") {
		Forcolor = APIWraper->Black;
	}

	if (fontColor == "Red") {
		Forcolor = APIWraper->Red;
	}

	if (backColor == "White") {
		Backcolor = APIWraper->Black;
	}


	APIWraper->Print(msg, x, y, Forcolor, Backcolor);
}