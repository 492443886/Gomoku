#pragma once

/*
File: Gomoku.hpp
Autor: Chunhui Ma
Content: A GameControl Object
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#include <vector>
#include "Record.hpp"
#include "Model.hpp"
#include "Commands.hpp"

class Gomoku : public Model{

public:

	std::string winer;

	std::string Player1Name;
	std::string Player2Name;

	std::string Player1Color;
	std::string Player2Color;

private:
	
	const int WINMUNBER = 5;
	int layout[15][15];
	bool winFlag;
	int turn;
	int longestRun;

	std::vector<Record> records;

private:

	/*
	Method Name: isDone
	Purpose: Check if some one win
	Parameter: int x, int y, int piece
	Return: bool
	*/
	bool isDone(int x, int y, int piece);

	/*
	Method Name: getLine3
	Purpose: get line 3
	Parameter: int x , int y
	Return: vector of getLine
	*/
	std::vector<int> getLine3(int x, int y);

	/*
	Method Name: getLine4
	Purpose: get line 4
	Parameter: int x, int y
	Return: vector of getLine4
	*/
	std::vector<int> getLine4(int x, int y);


	/*
	Method Name: exam
	Purpose: exame the line
	Parameter: a vector
	Return: bool
	*/
	bool exam(const std::vector<int>& line, int tester);

	inline void setP1Name(std::string s) {

		if (Player1Name.length() < 13) {
			Player1Name += s;
			notify();
		}
		
		
	}
	inline void setP2Name(std::string s) {

		if (Player2Name.length() < 12) {
			Player2Name += s;
			notify();
		}
	}
	inline void ChangeColorP1(std::string c) {

		Player1Color = c;
		notify();
	}
	inline void ChangeColorP2(std::string c) {

		Player2Color = c;
		notify();
	}
	/*
	Method Name: put
	Purpose: put a piece in
	Parameter: int x, int y, int piece
	Return: bool
	*/
	bool put(int x, int y/*, int piece*/);
	/*
	Method Name: Uodo
	Purpose: undo the step
	Parameter: none
	Return: Record
	*/
	void Undo();
	/*
	Method Name: clear
	Purpose: clear the layout
	Parameter: none
	Return: void
	*/
	void clear();

public:

	//Constructor
	Gomoku();
	inline int getTurn() {
		return turn;
	}
	inline int getLongestRun() {
		return longestRun;
	}
	inline std::vector<Record> getRecords (){
		return records;
	}
	/*
	Method Name: process
	Purpose: process the layout
	Parameter: none
	Return: void
	*/
	void process(std::shared_ptr<Command> command)override;

	/*
	Method Name: isWin
	Purpose: return the win flag
	Parameter: none
	Return: bool
	*/
	bool isWin();

};