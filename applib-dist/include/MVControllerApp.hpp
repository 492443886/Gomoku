#pragma once

/*
File: MVControllerApp.hpp
Autor: Chunhui Ma
Content: MVControllerApp
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <ConsoleApp.hpp>
#include <vector>
#include "View.hpp"
#include "Model.hpp"
#include <memory>
class MVControllerApp: public ConsoleApp {

private:

	bool done = false;
	std::shared_ptr<Model> model;

protected:

	std::vector<std::shared_ptr<View>> Views;


	/*
	Method Name: SetModel
	Purpose: set Model
	Parameter: model
	Return: void
	*/
	inline void SetModel(std::shared_ptr<Model> model) {
		this->model = model;
	}
	/*
	Method Name: addView
	Purpose: set Model
	Parameter: view
	Return: void
	*/
	inline void addView(std::shared_ptr<View> view) {
		Views.push_back(view);

	}
	/*
	Method Name: EventPump
	Purpose: pump Event
	Parameter: none
	Return: void
	*/
	void EventPump();

};