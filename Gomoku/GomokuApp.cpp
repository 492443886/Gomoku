/*
File: Gomoku.cpp
Autor: Chunhui Ma
Content: main method and the method body of Gomoku
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/

#include "GomokuApp.hpp"
#include "Event.hpp"
#include "Gomoku.hpp"
#include "XError.hpp"
#include "Model.hpp"

using namespace std;


GomokuApp::GomokuApp() {

	gomokuModel = shared_ptr<Gomoku>(new Gomoku());
	SetModel(gomokuModel);

	gameMoveView = shared_ptr<GameMoveView>(new GameMoveView(console, gomokuModel));
	scoreView = shared_ptr<ScoreView>(new ScoreView(console, gomokuModel));
	gameBoardView = shared_ptr<GameBoardView>(new GameBoardView(console, gomokuModel));
	playersView = shared_ptr<PlayersView>(new PlayersView(console, gomokuModel));

	addView(gameMoveView);
	addView(scoreView);
	addView(gameBoardView);
	addView(playersView);

	gomokuModel->attach(gameMoveView);
	gomokuModel->attach(playersView);
	gomokuModel->attach(scoreView);
	gomokuModel->attach(gameBoardView);


	messageX = 80;
	messageY = 5;

	WindowX = 100;
	WindowY = 40;
	GridX = 5;
	GridY = 6;

	turns = 0;

	playerNumber = 0;
}



int GomokuApp::execute() {

	console->StoreState();
	console->SetTitle("Gomoku");
	console->resizeWindow(WindowX, WindowY);

	console->HideCursor();

	gameMoveView->InitialDraw();
	scoreView->InitialDraw();
	gameBoardView->InitialDraw();
	playersView->InitialDraw();
	//printGrid(GridX, GridY);

	EventPump();
	{
		//while (!done) {
		//	vector<Event> events = console->getEvents();

		//	for (auto e : events) {
		//		if (e.EventName == "r") {

		//			gameControl.clear();

		//			console->Print("                  ", messageX, messageY, "White", "Black");
		//			console->Print("                  ", messageX, messageY + 1, "White", "Black");
		//			while (true) {
		//				Record record = gameControl.Uodo();
		//				if (record.piece == -1)
		//					break;
		//				int displayX = GridX + record.x * 4 + 2;
		//				int displayY = GridY + record.y * 2 + 1;
		//				console->Print(" ", displayX, displayY, "", "");
		//			}
		//			turns = 0;

		//		}
		//		if (e.EventName == "Right" && !gameControl.isWin()) {

		//			
		//			Record record = gameControl.Uodo();
		//			if (record.piece != -1) {
		//				turns--;

		//				int displayX = GridX + record.x * 4 + 2;
		//				int displayY = GridY + record.y * 2 + 1;
		//				console->Print(" ", displayX, displayY, "", "");
		//			}
		//		}
		//		if (e.EventName == "Left" && !gameControl.isWin()) {

		//			int x = e.x - GridX;
		//			int y = e.y - GridY;
		//			BlockDecider(x, y);
		//			bool isPrint = false;
		//			if (x != -1 && y != -1) {
		//				isPrint = gameControl.put(x, y, turns % 2 + 1);
		//			}
		//			if (isPrint) {

		//				int piece = turns % 2 + 1;
		//				string playerSybol = "";
		//				string color = "";
		//				string backColor = "";
		//				if (piece == 1) {
		//					playerSybol = "X";
		//					color = "Red";
		//				}
		//				if (piece == 2) {

		//					playerSybol = "O";
		//					color = "Black";
		//				}

		//				int displayX = GridX + x * 4 + 2;
		//				int displayY = GridY + y * 2 + 1;

		//				console->Print(playerSybol, displayX, displayY, color, backColor);

		//				if (gameControl.isWin()) {

		//					if (piece == 1) {
		//						console->Print("X Win!            ", messageX, messageY, color, backColor);
		//						console->Print("Press r to restart", messageX, messageY + 1, color, backColor);
		//					}
		//					if (piece == 2) {
		//						console->Print("O Win!            ", messageX, messageY, color, backColor);
		//						console->Print("Press r to restart", messageX, messageY + 1, color, backColor);
		//					}
		//				}
		//				
		//				
		//				turns++;
		//			}
		//		}

		//		if (e.EventName == "cPressed") {
		//			done = true;
		//		}
		//	}
		//}
	}


	console->restoreState();

	return 0;
}


void GomokuApp::BlockDecider(int& x, int& y) {

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



void  GomokuApp::printGrid(int x, int y) {

	int positionX = x;
	int positionY = y;
	for (int i = 0; i < 30; i++) {
		console->Print("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+", positionX, positionY + i, "", "");
		i++;
		console->Print("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |", positionX, positionY + i, "", "");
	}
	console->Print("+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+", positionX, positionY + 30, "", "");

}