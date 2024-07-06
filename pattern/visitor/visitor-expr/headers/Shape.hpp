#pragma once
#include "CyclicVisitor.hpp"

struct Shape {
	virtual void accept (Visitor* v)=0;
	virtual void draw ()=0;
};

struct Circle : Shape {
	virtual void accept (Visitor* v) override {
		v -> visit(this); 
	}
	virtual void draw () override {
		cout << "Circle::draw is called." << endl;
	}	
};

struct Square : Shape {
	virtual void accept (Visitor* v) override {
		v -> visit(this); 
	}
	virtual void draw () override {
		cout << "Square::draw is called." << endl;
	}	
};

