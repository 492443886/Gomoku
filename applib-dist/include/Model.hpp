#pragma once
#include <set>
#include "View.hpp"
#include <memory>
/*
File: Model.hpp
Autor: Chunhui Ma
Content: a Model object used to be used as a Model
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
class Model {
	std::set<std::shared_ptr<View>> observers;
public:
	virtual ~Model() {}
	inline virtual void process(std::shared_ptr<Command> command) {};
	inline void attach(std::shared_ptr<View> p) { observers.insert(p); }
	inline void detach(std::shared_ptr<View> p) { observers.erase(p); }
protected:
	inline void notify() {
		for (auto observer : observers)
			observer->update();
	}
};