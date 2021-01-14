#pragma once
/*
File: Commands.hpp
Autor: Chunhui Ma
Content: a lots of Command Class
Date: March 2, 2018
Compiler Version: 19.00.30729.01 for 80x86

*/
#include <Command.hpp>
#include <string>
/*
Class Name: PutCommand
*/
class PutCommand :public Command {

public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "Put";
	};
	int x;
	int y;
};

/*
Class Name: UndoCommand

*/
class UndoCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "Undo";
	};
};
/*
Class Name: RestartCommand

*/
class RestartCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "Restart";
	};
};
/*
Class Name: P1ChangeColorCommand

*/
class P1ChangeColorCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P1ChangeColor";
	};
	std::string color;
};

/*
Class Name: P2ChangeColorCommand
*/
class P2ChangeColorCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P2ChangeColor";
	};
	std::string color;
};

/*
Class Name: P1ClearNameCommand
*/
class P1ClearNameCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P1ClearName";
	};
};
/*
Class Name: P2ClearNameCommand
*/
class P2ClearNameCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P2ClearName";
	};
};
/*
Class Name: P1ChangeNameCommand
*/
class P1ChangeNameCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P1ChangeName";
	};
	std::string Char;
};
/*
Class Name: P2ChangeNameCommand
*/
class P2ChangeNameCommand :public Command {
public:
	/*
	Method Name: toString
	Purpose: return string
	Parameter:
	Return: string
	*/
	inline std::string toString() {
		return "P2ChangeName";
	};
	std::string Char;
};