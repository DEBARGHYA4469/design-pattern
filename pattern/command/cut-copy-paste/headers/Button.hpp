#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Button {
	string name;
	function<void()> fcn;
	Button (string name) : name (name) {} 
	void bindOnClick (function<void()> fcn) { this->fcn = fcn; }
	void onClick () { cout << "On click button:\n"; fcn(); }
}; 