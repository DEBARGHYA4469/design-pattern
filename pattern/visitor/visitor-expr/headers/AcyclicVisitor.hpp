#pragma once
#include "Expression.hpp"

using namespace std;

template <typename T>
struct Visitor{
	virtual void visit (T* v)=0;
}; 

/* Note: Base Visitor is just based of abstract Expression class */
struct BaseVisitor
{
	virtual void visit (Expression* expr)=0;
};

struct ExpressionPrinter1 : BaseVisitor, Visitor<Number>, Visitor<Plus> {
	virtual void visit (Expression* expr) override {} // override ... 
	virtual void visit (Plus* expr) override;
	virtual void visit (Number* number) override;
}; 

struct ExpressionPrinter2 : BaseVisitor, Visitor<Number>, Visitor<Plus> {
	virtual void visit (Expression* expr) override {} // override ... 
	virtual void visit (Plus* expr) override;
	virtual void visit (Number* number) override;
}; 

struct NumberPrinter : BaseVisitor, Visitor<Number> {
	virtual void visit (Expression* expr) override {} // override ... 
	virtual void visit (Number* number) override;
}; 

struct OnlyPlusPrinter : BaseVisitor, Visitor<Plus> {
	virtual void visit (Expression* expr) override {} // override ... 
	virtual void visit (Plus* expr) override;
}; 