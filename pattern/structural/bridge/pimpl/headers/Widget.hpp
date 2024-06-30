#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

class Widget {
private:
	class WidgetImpl; // foreward declaration 
	std::unique_ptr <WidgetImpl> pImpl; 
public:
	Widget (std::string name); 
	~Widget ();  	 
	void show () const;
	void move () const;
	void hide () const;
}; 

