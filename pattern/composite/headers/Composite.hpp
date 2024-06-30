#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Interface for movable GUI objects */
class Graphic {
public:
	virtual ~Graphic() = default;
	virtual void move (int, int) = 0; 
	virtual void draw () = 0; 
};

class Dot : public Graphic {
protected: 
	int x, y; 
public:
	Dot (int x, int y) : x(x), y(y) {
		std::cout << "A dot is constructed at: " << x << "," << y << std::endl;
	} 
	virtual void move (int dx, int dy) override {
		std::cout << "A dot is moved to: " << x << "," << y << std::endl;
		x = x + dx; 
		y = y + dy; 
	} 
	virtual void draw () override {
		std::cout << "A dot is drawn at: " << x << "," << y << std::endl;
	}	
}; 

class Circle : public Dot {
private:
	int radius; 
public:
	Circle (int x, int y, int radius) : Dot(x, y), radius(radius) {
		std::cout << "A circle is constructed at: " << x << "," << y << std::endl;
	}
	virtual void draw () override {
		std::cout << "A circle is drawn at: " << x << "," << y << std::endl;
	}
};

class CompoundGraphics : public Graphic {
private: 
	std::vector<Graphic* > collections; 
public: 
	CompoundGraphics () = default;
	~CompoundGraphics () {
		for (Graphic* g: collections) 
			delete g; 
	}
	void add (Graphic* g) {
		collections.emplace_back (g);
	}
	void remove (Graphic* g); 

	virtual void move (int dx, int dy) override {
		for (Graphic* g: collections)
			g->move (dx, dy);
	}
	virtual void draw () override {
		for (Graphic* g: collections)
			g->draw();
	}
}; 


class ImageEditor {
private:
	CompoundGraphics* cg;
public:
	ImageEditor () { cg = new CompoundGraphics(); }
	~ImageEditor () { delete cg; }
	void load (Graphic* _g){
		cg->add (_g);
	}
	void groupSelected (std::vector<Graphic*> garr) {
		// remove all garr elements from cg. 
		// draw all of them together. 
	}
};
