#include "GameBoardView.hpp"
#include <View.hpp>

using namespace std;



GameBoardView::GameBoardView(shared_ptr<Console> console,shared_ptr<Gomoku> gomoku) {

	this->console = console;
	this->gomoku = gomoku.get();

}

void GameBoardView::update() {


	for (int i = 0; i < BLOCKS; i++)
	{
		for (int o = 0; o < BLOCKS; o++)
		{
			console->Print(" ", (STARTX + 2) + (i * 4), (STARTY + 1) + (o * 2), "Red", "");
		}
	}

	for (auto record : gomoku->getRecords()) {
		int displayX = STARTX + record.x * 4 + 2;
		int displayY = STARTY + record.y * 2 + 1;


		if (record.piece == 1) {
			console->Print("X", displayX, displayY, gomoku->Player1Color, "");
		}
		else if (record.piece == 2) {
			console->Print("O", displayX, displayY, gomoku->Player2Color, "");
		}
	}

}

shared_ptr<Command> GameBoardView::EventPush(Event e) {

	if (e.EventName == "Left" && !gomoku->isWin()) {

		int x = e.x - STARTX;
		int y = e.y - STARTY;
		BlockDecider(x, y);

		if (x != -1 && y != -1) {
			shared_ptr<PutCommand> c = shared_ptr<PutCommand>(new PutCommand());
			c->x = x;
			c->y = y;
			return c;

		}

	}

	if (e.EventName == "Right" && !gomoku->isWin()) {
		shared_ptr<UndoCommand> c = shared_ptr<UndoCommand>(new UndoCommand());
		return c;

	}

	if (e.EventName == "Restart") {

		shared_ptr<RestartCommand> c = shared_ptr<RestartCommand>(new RestartCommand());
		return c;

	}
	return nullptr;
}
void GameBoardView::BlockDecider(int& x, int& y) {

	if (x % 4 != 0 && y % 2 != 0) {
		int tempX = x / 4;
		int tempY = y / 2;
		if (tempX < 15 && tempX >= 0 && tempY >= 0 && tempY < 15) {
			x = tempX;
			y = tempY;
			return;
		}

	}
	x = -1;
	y = -1;
}


bool GameBoardView::isHit(Event event) {

	if (event.EventName == "Left") {

		bool test = event.x >= STARTX && event.y >= STARTY && event.x <= STARTX + WIDTH && event.y <= STARTY + HEIGH;
		if (test) {
			return true;
		}
	}
	if (event.EventName == "Right") {

		return true;
	}
	if (event.EventName == "Restart") {

		return true;
	}


	return false;

};

void GameBoardView::InitialDraw() {
	printGrid(STARTX, STARTY);
}

void  GameBoardView::printGrid(int x, int y) {

	int positionX = x;
	int positionY = y;
	for (int i = 0; i < 30; i++) {
		console->Print("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+", positionX, positionY + i, "", "");
		i++;
		console->Print("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |", positionX, positionY + i, "", "");
	}
	console->Print("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+", positionX, positionY + 30, "", "");

}