#pragma once
/*
File: GameBoardView.hpp
Autor: Chunhui Ma
Content: a View object used to be used as a View
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#include "Gomoku.hpp"
#include <ConsoleApp.hpp>
#include <View.hpp>
#include "Commands.hpp"

class GameBoardView : public View {

private:
	std::shared_ptr<Console> console;
	Gomoku* gomoku;

public:
	const int STARTX = 5;
	const int STARTY = 6;

	const int WIDTH = 61;
	const int HEIGH = 61;

	const int BLOCKS = 15;

public:
	//constructor
	GameBoardView(std::shared_ptr<Console> console, std::shared_ptr<Gomoku> gomoku);
	/*
	Method Name: update
	Purpose: Update the graph
	Parameter:
	Return:
	*/
	void update();
	/*
	Method Name: EventPush
	Purpose: Handle The events
	Parameter: Event
	Return:Command
	*/
	std::shared_ptr<Command> EventPush(Event e) override;
	/*
	Method Name: isHit
	Purpose: execute the programe
	Parameter: Event
	Return: Command
	*/
	bool isHit(Event event);
	/*
	Method Name: InitialDraw
	Purpose: IntialDraw 
	Parameter:
	Return: void
	*/
	void InitialDraw();

private:
	/*
	Method Name: printGrid
	Purpose: print the Grid
	Parameter: int int
	Return: 
	*/
	void  printGrid(int x, int y);

	/*
	Method Name: BlockDecider
	Purpose: A helper method to decide block
	Parameter: int, int
	Return:
	*/
	void BlockDecider(int& x, int& y);


};