#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Decorator design pattern with mixin inheritance and perfect forewarding */

class Shape {
public:
	virtual std::string  draw () const = 0; 
};

class Circle : public Shape {
private:
	int R;
public:
	int _R() const { return R; }
	Circle (int R) : R(R) {}  
	virtual std::string draw () const {
		std::ostringstream oss; 
		oss << "Drawing a Circle with radius " << R << " "; 
		return oss.str();
	}
};

class Square : public Shape {
private:
	int width;
public:
	int _width () const { return width; } 
	Square (int width) : width(width) {}  
	virtual std::string draw () const {
		std::ostringstream oss; 
		oss << "Drawing a Square with radius " << width << " "; 
		return oss.str();
	}
};

/* Decorator class I*/
template <typename T> 
class ColoredShape : public T {
	static_assert (std::is_base_of<Shape, T>::value, "T must be of Shape type");
private:
	std::string color; 
public:
	std::string _color() const { return this->color; } 
	template <typename ...Args> 
	ColoredShape (std::string color, Args ...args) : T (std::forward<Args>(args)...), color (color) {}
	virtual std::string draw () const {
		std::ostringstream oss; 
		oss << T::draw() << "of color " << color << " "; 
		return oss.str();
	} 
};  

/* Decorator class I*/
template <typename T> 
class TransparentShape : public T {
	static_assert (std::is_base_of<Shape, T>::value, "T must be of Shape type");
private:
	std::string transparency; 
public:
	std::string _transparency() const { return transparency; } 
	template <typename ...Args> 
	TransparentShape (std::string transparency, Args ...args) : T (std::forward<Args>(args)...), transparency (transparency) {}
	virtual std::string draw () const {
		std::ostringstream oss; 
		oss << T::draw() << "with transparency " << transparency << " "; 
		return oss.str();
	} 
}; 

