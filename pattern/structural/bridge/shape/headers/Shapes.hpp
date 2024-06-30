#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include "Renderer.hpp"

class Shape {
public:
	virtual void draw () = 0;
}; 

class Circle : public Shape {
public:
	Circle (Renderer* renderer) : renderer (renderer) {}  
	virtual void draw () override {
		renderer->render();
		std::cout << "Circle::draw is called." << std::endl;
	}
private: 
	Renderer *renderer; 
};


class Square : public Shape {
public:
	Square (Renderer* renderer) : renderer (renderer) {}  
	virtual void draw () override {
		renderer->render();
		std::cout << "Square::draw is called." << std::endl;
	}
private: 
	Renderer *renderer; 
};