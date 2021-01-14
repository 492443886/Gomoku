#pragma once

/*
File: GameMoveView.hpp
Autor: Chunhui Ma
Content: a View object used to be used as a View
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include "Gomoku.hpp"
#include <ConsoleApp.hpp>
#include <vector>
#include <View.hpp>

class GameMoveView : public View {

private:
	std::shared_ptr<Console> console;
	Gomoku* gomoku;

public:

	const int STARTX = 70;
	const int STARTY = 6;
public:

	GameMoveView(std::shared_ptr<Console> console, std::shared_ptr<Gomoku> gomoku);
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
	Return: Command
	*/
	std::shared_ptr<Command> EventPush(Event e) override;
	/*
	Method Name: isHit
	Purpose: execute the programe
	Parameter: Event
	Return: bool
	*/
	virtual bool isHit(Event event);
	/*
	Method Name: InitialDraw
	Purpose: IntialDraw
	Parameter:
	Return: 
	*/
	void InitialDraw();

};