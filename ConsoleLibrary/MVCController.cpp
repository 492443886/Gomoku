#include "MVControllerApp.hpp"
using namespace std;
 void MVControllerApp::EventPump() {

	while (!done) {

		vector<Event> events = console->getEvents();

		for (auto e : events) {

			if (e.EventName == "")
				continue;

			for (size_t i = 0; i < Views.size(); i++)
			{
				if (Views[i]->isHit(e)) {

					std::shared_ptr<Command> command = Views[i]->EventPush(e);
					if (command != nullptr)
						model->process(command);
				}
			}
			if (e.EventName == "cPressed") {
				done = true;
			}
		}
	}
}