#include "GameMoveView.hpp"
using namespace std;
GameMoveView::GameMoveView(shared_ptr<Console> console, shared_ptr<Gomoku> gomoku) {

	this->console = console;
	this->gomoku = gomoku.get();
}

void GameMoveView::update() {

	for (int i = 0; i < 30; i++)
	{
		console->Print("            ", STARTX, STARTY + i, "", "");
	}



	vector<Record> records = gomoku->getRecords();

	for (size_t i = records.size(); i > 0 && (records.size() - i) < 28; i--)
	{
		Record record = records[static_cast<int>(i) - 1];

		char c = 65 + record.x;
		string color = (record.piece == 1) ? gomoku->Player1Color : gomoku->Player2Color;

		string msg = to_string(static_cast<int>(i)) + " (" + c + ", " + to_string(record.y) + ")";
		console->Print(msg, STARTX + 1, STARTY + 1 + static_cast<int>(records.size()) - static_cast<int>(i), color, "");

	}

}
std::shared_ptr<Command> GameMoveView::EventPush(Event e) {

	return nullptr;
};
bool GameMoveView::isHit(Event event) {
	return false;
};
void GameMoveView::InitialDraw() {

	for (size_t i = 0; i < 31; i++)
	{
		console->Print("                         ", STARTX, STARTY + static_cast<int>(i), "", "");
	}

}