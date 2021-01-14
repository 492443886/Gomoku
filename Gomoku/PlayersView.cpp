#include "PlayersView.hpp"


PlayersView::PlayersView(std::shared_ptr<Console> console, std::shared_ptr<Gomoku> gomoku) {

	this->console = console;
	this->gomoku = gomoku.get();
	p1Foucs = false;
	p2Foucs = false;
}

void PlayersView::update() {


	console->Print("            ", STARTX + 1, STARTY + 1, gomoku->Player1Color, "");
	console->Print("            ", STARTX2 + 1, STARTY + 1, gomoku->Player2Color, "");

	console->Print(gomoku->Player1Name, STARTX + 1, STARTY + 1, gomoku->Player1Color, "");
	console->Print(gomoku->Player2Name, STARTX2 + 1, STARTY + 1, gomoku->Player2Color, "");

	if (gomoku->isWin() == true) {
		console->Print("The winner is ", STARTX2 + 10, STARTY + 2, "", "");
		console->Print(gomoku->winer, STARTX2 + 10, STARTY + 3, "", "");
	}

	else if (!gomoku->isWin()) {
		console->Print("              ", STARTX2 + 10, STARTY + 2, "", "");
		console->Print("              ", STARTX2 + 10, STARTY + 3, "", "");
	}

}


std::shared_ptr<Command> PlayersView::EventPush(Event e) {



	if (e.y == STARTY + 3) {
		if (e.x == STARTX + 1) {

			std::shared_ptr<P1ChangeColorCommand> c = std::shared_ptr<P1ChangeColorCommand>(new P1ChangeColorCommand());
			c->color = "Red";
			return c;
		}
		if (e.x == STARTX + 3) {
			std::shared_ptr<P1ChangeColorCommand> c = std::shared_ptr<P1ChangeColorCommand>(new P1ChangeColorCommand());
			c->color = "Green";
			return c;
		}
		if (e.x == STARTX + 5) {

			std::shared_ptr<P1ChangeColorCommand> c = std::shared_ptr<P1ChangeColorCommand>(new P1ChangeColorCommand());
			c->color = "Black";
			return c;
		}

		if (e.x == STARTX2 + 1) {
			std::shared_ptr<P2ChangeColorCommand> c = std::shared_ptr<P2ChangeColorCommand>(new P2ChangeColorCommand());
			c->color = "Red";
			return c;

		}
		if (e.x == STARTX2 + 3) {
			std::shared_ptr<P2ChangeColorCommand> c = std::shared_ptr<P2ChangeColorCommand>(new P2ChangeColorCommand());
			c->color = "Green";
			return c;
		}
		if (e.x == STARTX2 + 5) {
			std::shared_ptr<P2ChangeColorCommand> c = std::shared_ptr<P2ChangeColorCommand>(new P2ChangeColorCommand());
			c->color = "Black";
			return c;
		}
	}

	bool test = e.x >= STARTX && e.y >= STARTY && e.x <= STARTX + WIDTH && e.y <= STARTY + HEIGHT - 3;
	if (test) {
		p1Foucs = true;
		std::shared_ptr<P1ClearNameCommand> c = std::shared_ptr<P1ClearNameCommand>(new P1ClearNameCommand());
		return c;
	}
	test = e.x >= STARTX2 && e.y >= STARTY && e.x <= STARTX2 + WIDTH && e.y <= STARTY + HEIGHT - 3;

	if (test) {
		p2Foucs = true;
		std::shared_ptr<P2ClearNameCommand> c = std::shared_ptr<P2ClearNameCommand>(new P2ClearNameCommand());
		return c;
	}

	if (e.EventName.length() == 1) {

		if (p1Foucs) {
			std::shared_ptr<P1ChangeNameCommand> c = std::shared_ptr<P1ChangeNameCommand>(new P1ChangeNameCommand());
			c->Char = e.EventName;
			return c;
		}
		if (p2Foucs) {
			std::shared_ptr<P2ChangeNameCommand> c = std::shared_ptr<P2ChangeNameCommand>(new P2ChangeNameCommand());
			c->Char = e.EventName;
			return c;
		}

	}
	return nullptr;
}


bool PlayersView::isHit(Event event) {



	if (event.EventName == "Left") {
		if (p1Foucs) {

			p1Foucs = false;
		}
		if (p2Foucs) {

			p2Foucs = false;
		}

		bool test = event.x >= STARTX && event.y >= STARTY && event.x <= STARTX + WIDTH && event.y <= STARTY + HEIGHT;
		if (test) {

			return true;
		}
		test = event.x >= STARTX2 && event.y >= STARTY && event.x <= STARTX2 + WIDTH && event.y <= STARTY + HEIGHT;

		if (test) {

			return true;
		}
	}

	if ((p1Foucs || p2Foucs) && event.EventName.length() == 1) {

		return true;

	}


	return false;

}

void PlayersView::InitialDraw() {


	for (size_t i = 0; i < 4; i++)
	{
		console->Print("                   ", STARTX, STARTY + static_cast<int>(i), "", "");
	}


	console->Print("Player1 Name: ", STARTX + 1, STARTY, "", "");
	console->Print(gomoku->Player1Name, STARTX + 1, STARTY + 1, gomoku->Player1Color, "");
	console->Print("Color: ", STARTX + 1, STARTY + 2, "", "");
	console->Print("X", STARTX + 1, STARTY + 3, "Red", ""); console->Print("X", STARTX + 3, STARTY + 3, "Green", ""); console->Print("X", STARTX + 5, STARTY + 3, "Black", "");



	for (size_t i = 0; i < 4; i++)
	{
		console->Print("                        ", STARTX2, STARTY + static_cast<int>(i), "", "");
	}


	console->Print("Player2 Name: ", STARTX2 + 1, STARTY, "", "");
	console->Print(gomoku->Player2Name, STARTX2 + 1, STARTY + 1, gomoku->Player2Color, "");
	console->Print("Color: ", STARTX2 + 1, STARTY + 2, "", "");
	console->Print("O", STARTX2 + 1, STARTY + 3, "Red", ""); console->Print("O", STARTX2 + 3, STARTY + 3, "Green", ""); console->Print("O", STARTX2 + 5, STARTY + 3, "Black", "");


}