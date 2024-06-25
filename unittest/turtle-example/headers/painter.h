#pragma once 
#include "turtle.h" 

class Painter {
	Turtle* turtle; 
	public: 
		Painter (Turtle* turtle) : turtle (turtle) {}
		bool DrawCircle (int a, int b, int c) {
			turtle->PenDown();
			return true;
		} 
};