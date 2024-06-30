#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

class RoundPegInterface {
public:
	virtual double get_radius () const = 0;
}; 

class SquarePegInterface {
public:
	virtual double get_width () const = 0;
}; 

class RoundPeg : public RoundPegInterface{
public:
	RoundPeg (double radius) : radius (radius) {} 
	virtual double get_radius () const override {
		return this->radius;
	};
private: 
	double radius; 	 
}; 

class SquarePeg : public SquarePegInterface{
public:
	SquarePeg (double width) : width (width) {} 
	virtual double get_width () const override {
		return this->width;
	};
private: 
	double width; 	 
};

class RoundHole {
private:
	double radius; 
public:
	RoundHole (double radius) : radius(radius) {}
	bool fits (RoundPegInterface* roundpeg) {
		return roundpeg->get_radius() < this->radius;
	} 
}; 

class SquareToRoundPegAdapter : public RoundPegInterface {
private:
	SquarePegInterface* squarePeg;
public:
	SquareToRoundPegAdapter (SquarePegInterface* squarePeg) : squarePeg (squarePeg) {} 
	virtual double get_radius () const override {
		return squarePeg -> get_width() * sqrt (2) / 2.0;
	} 
}; 

