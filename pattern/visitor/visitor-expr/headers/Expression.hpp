#pragma once
#include "bits/stdc++.h"

/* Create a expression tree for ((1+2) + (2+3)) */

struct BaseVisitor;

struct Expression { 
	virtual ~Expression () = default;
	virtual void accept (BaseVisitor* v)=0;
}; 

struct Plus : Expression {
	Expression*left, *right;
	Plus (Expression* left, Expression* right) : left (left), right (right) {}
	virtual void accept (BaseVisitor* v);
};

struct Number : Expression {
	int number; 
	Number(int number) : number (number) {}
	virtual void accept (BaseVisitor* v);
};