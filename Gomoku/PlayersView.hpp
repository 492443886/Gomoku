#pragma once

/*
File: PlayersView.hpp
Autor: Chunhui Ma
Content: a View object used to be used as a View
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <ConsoleApp.hpp>
#include <vector>
#include "View.hpp"
#include "Gomoku.hpp"
#include <memory>
class PlayersView : public View {
private:
	std::shared_ptr<Console> console;
	Gomoku* gomoku;
	bool p1Foucs;
	bool p2Foucs;

public:
	const int STARTX = 5;
	const int STARTX2 = 25;

	const int STARTY = 1;

	const int WIDTH = 20;
	const int HEIGHT = 4;
public:


	PlayersView(std::shared_ptr<Console> console, std::shared_ptr<Gomoku> gomoku);
	/*
	Method Name: update
	Purpose: Update the graph
	Parameter:
	Return:
	*/
	void update() override;
	/*
	Method Name: EventPush
	Purpose: Handle The events
	Parameter: Event
	Return: Commad
	*/
	std::shared_ptr<Command> EventPush(Event e) override;
	/*
	Method Name: isHit
	Purpose: execute the programe
	Parameter: Event
	Return: bool
	*/
	bool isHit(Event event);
	/*
	Method Name: InitialDraw
	Purpose: IntialDraw
	Parameter:
	Return: o
	*/
	void InitialDraw();
};
