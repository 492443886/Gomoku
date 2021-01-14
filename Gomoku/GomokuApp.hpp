/*
File:GomokuApp.hpp
Autor: Chunhui Ma
Content: GomokuApp class, while is a console game
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#pragma once
#include <memory>
#include "Gomoku.hpp"

#include "ScoreView.hpp"
#include "GameBoardView.hpp"
#include <ConsoleApp.hpp>
#include <MVControllerApp.hpp>
#include "PlayersView.hpp"
#include "GameMoveView.hpp"

class GomokuApp: public MVControllerApp
{
private:

	
	std::shared_ptr<ScoreView> scoreView;
	std::shared_ptr<GameBoardView> gameBoardView;
	std::shared_ptr<PlayersView> playersView;
	std::shared_ptr<GameMoveView> gameMoveView;

	std::shared_ptr<Gomoku> gomokuModel;

	int turns;


public:

	int messageX;
	int messageY;

	int WindowX;
	int WindowY;
	int GridX;
	int GridY;
	int playerNumber;



	//contructor
	GomokuApp();

	/*
	Method Name: execute
	Purpose: execute the programe
	Parameter:
	Return:
	*/
	int execute();

private:
	/*
	Method Name: BlockDecider
	Purpose: to decide the block
	Parameter: int x, int y
	Return: void 
	*/
	void BlockDecider(int& x, int& y);

	/*
	Method Name: print 
	Purpose: print a grid
	Parameter: int x, int y
	Return: void
	*/ 
	void printGrid(int x, int y);
} gomoku;