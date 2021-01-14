#include "ScoreView.hpp"

bool ScoreView::isHit(Event event) {
	return false;

};


void ScoreView::update(){

	console->Print("  ", STARTX + 15, STARTY + 1, "", "");
	console->Print(std::to_string(gomoku->getLongestRun()), STARTX + 15, STARTY + 1, "", "");
	console->Print("  ", STARTX + 35, STARTY + 1, "", "");
	console->Print(std::to_string(gomoku->getTurn() - 1), STARTX + 35, STARTY + 1, "", "");
	console->Print("Press \"SPACE\" will restart game", STARTX + 1, STARTY + 2, "", "");
}

std::shared_ptr<Command> ScoreView::EventPush(Event e) {

	return nullptr;
}

ScoreView::ScoreView(std::shared_ptr<Console> console, std::shared_ptr<Gomoku> gomoku) {

	this->console = console;
	this->gomoku = gomoku.get();

}
void ScoreView::InitialDraw() {

	for (size_t i = 0; i < 4; i++)
	{
		console->Print("                                             ", STARTX, STARTY + static_cast<int>(i), "", "");
	}


	console->Print("Longest Run: ", STARTX + 1, STARTY + 1, "", "");
	console->Print("Piece played: ", STARTX + 20, STARTY + 1, "", "");

	console->Print(std::to_string(gomoku->getLongestRun()), STARTX + 15, STARTY + 1, "", "");
	console->Print(std::to_string(gomoku->getTurn() - 1), STARTX + 35, STARTY + 1, "", "");

}