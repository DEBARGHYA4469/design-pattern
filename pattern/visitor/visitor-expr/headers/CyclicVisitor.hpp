#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Circle;
class Square; 

struct Visitor {
	virtual void visit (Circle* c);
	virtual void visit (Square* s);
};


struct DifferentVisitor : Visitor {
	virtual void visit (Circle* c) override;
	virtual void visit (Square* s) override;
};

