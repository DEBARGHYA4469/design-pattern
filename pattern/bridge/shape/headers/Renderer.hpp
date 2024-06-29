#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Interface for Renderer */
class Renderer {
public:
	virtual void render () = 0; 
};

class VectorRenderer : public Renderer {
public:
	virtual void render () override {
		std::cout << "Rendering as a Vector!" << std::endl;
	} 
}; 

class RasterRenderer : public Renderer {
public:
	virtual void render () override {
		std::cout << "Rendering as a Raster!" << std::endl;
	} 
}; 
