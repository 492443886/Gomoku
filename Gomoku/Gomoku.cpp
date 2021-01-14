#include "Gomoku.hpp"
/*
File: GameControl.cpp
Autor: Chunhui Ma
Content: Method body of GameControl
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/



using namespace std;
Gomoku::Gomoku() {
	Player1Name = "Please Edit";
	Player2Name = "Please Edit";
	Player1Color = "Black";
	Player2Color = "Red";

	longestRun = 0;
	turn = 1;
	winFlag = false;
	for (int i = 0; i < 15; i++) {
		for (int x = 0; x < 15; x++) {
			layout[i][x] = 0;
		}
	}
}

bool Gomoku::put(int x, int y) {

	int piece = turn % 2 + 1;

	if (layout[x][y] == 0) {
		layout[x][y] = piece;
	}
	else {
		return false;
	}
	Record re;
	re.x = x;
	re.y = y;
	re.piece = piece;

	records.push_back(re);

	if (isDone(x, y, piece)) {
		winer = Player1Name;
		if (turn% 2 == 1) {
			winer = Player2Name;
		}
		 
		winFlag = true;
	}

	turn++;

	notify();

	return true;
}

bool Gomoku::isWin() {
	return winFlag;
}

bool Gomoku::isDone(int x, int y, int piece) {

	longestRun = 0;
	vector<int> line1;
	vector<int> line2;
	vector<int> line3;
	vector<int> line4;

	for (int i = 0; i < 15; i++) {
		line1.push_back(layout[x][i]);
	}

	for (int i = 0; i < 15; i++) {
		line2.push_back(layout[i][y]);
	}
	line3 = getLine3(x, y);
	line4 = getLine4(x, y);

	if (exam(line1, piece) || exam(line2, piece) || exam(line3, piece) || exam(line4, piece)) {

		
		return true;
	}

	return false;

}


vector<int> Gomoku::getLine3(int x, int y) {
	vector<int> line3;
	int k = x + y;
	if (k > 14) {
		x = k - 14;
		y = 14;
	}
	else {
		y = k;
		x = 0;
	}
	while (true) {
		line3.push_back(layout[x][y]);
		x++;
		y--;
		if (x > 14 || y < 0) {
			break;
		}
	}
	return line3;
}

vector<int> Gomoku::getLine4(int x, int y) {
	vector<int> line4;
	int k = y - x;
	if (k < 0) {
		y = 0;
		x = y - k;
	}
	else {
		y = k;
		x = 0;
	}
	while (true) {
		line4.push_back(layout[x][y]);
		x++;
		y++;
		if (x > 14 || y > 14) {
			break;
		}
	}
	return line4;
}

void Gomoku::process(std::shared_ptr<Command> command){
	if (command->toString() == "Put") {

		PutCommand*  putCommand = dynamic_cast<PutCommand*>(command.get());
		put(putCommand->x, putCommand->y);

	}
	else if (command->toString() == "Undo") {
		Undo();
	}
	else if (command->toString() == "Restart") {
		clear();
	}
	else if (command->toString() == "P1ChangeColor") {
		P1ChangeColorCommand*  c = dynamic_cast<P1ChangeColorCommand*>(command.get());
		ChangeColorP1(c->color);
	}
	else if (command->toString() == "P2ChangeColor") {
		P2ChangeColorCommand*  c = dynamic_cast<P2ChangeColorCommand*>(command.get());
		ChangeColorP2(c->color);
	}
	else if (command->toString() == "P1ChangeName") {
		P1ChangeNameCommand*  c = dynamic_cast<P1ChangeNameCommand*>(command.get());
		setP1Name(c->Char);
	}
	else if (command->toString() == "P2ChangeName") {
		P2ChangeNameCommand*  c = dynamic_cast<P2ChangeNameCommand*>(command.get());
		setP2Name(c->Char);
	}
	else if (command->toString() == "P1ClearName") {

		Player1Name = "";
		notify();

	}
	else if (command->toString() == "P2ClearName") {
		Player2Name = "";
		notify();
	}
}

bool Gomoku::exam(const vector<int>& line, int tester) {

	int count = 0;

	for (auto i : line) {
		if (i == tester)
			count++;
		else
			count = 0;

		if (longestRun < count) {
			longestRun = count;
		}
		if (count == WINMUNBER) {

			return true;

		}
	}
	return false;

}

void  Gomoku::Undo() {

	Record record;
	if (records.size() != 0) {

		record = records.back();
		records.pop_back();

		layout[record.x][record.y] = 0;
		turn--;
		isDone(record.x, record.y, turn%2 +1);
		
		notify();
		
	}
	
}

void Gomoku::clear() {
	for (int i = 0; i < 15; i++) {
		for (int x = 0; x < 15; x++) {
			layout[i][x] = 0;
		}
	}

	longestRun = 0;
	turn = 1;
	records.clear();
	winFlag = false;

	notify();

}