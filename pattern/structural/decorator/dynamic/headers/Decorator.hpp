#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"


class A {
private:
	int x, y; 
public:
	A() = default; 
	~A() = default;
	void foo () const {}
}; 

inline void fun () {
	std::cout << "Hello" << std::endl;
}

class Shape {
public:
	virtual ~Shape () = 0;
	virtual void draw () = 0; 
}; 

inline Shape::~Shape() {} // ODR rule 

class Circle : public Shape {
private: 
	double r;
public:
	Circle (double r) : r(r) {}
	~Circle () = default;
	void resize () {}
	virtual void draw () override {
		std::cout << "Drawing a circle" << std::endl;
	}
};

class Square : public Shape {
private: 
	double width;
public:
	Square (double width) : width(width) {}
	~Square() = default;
	void set_width () {}
	virtual void draw () override {
		std::cout << "Drawing a square" << std::endl;
	}
};

class ColoredShape : public Shape {
private: 
	Shape* shape;
	std::string color; 
public:
	ColoredShape (Shape* shape, std::string color) : shape (shape), color (color) {}
	~ColoredShape () { delete shape; }
	virtual void draw () override {
		shape->draw();
	}
};