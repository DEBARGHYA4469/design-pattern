#include "AcyclicVisitor.hpp"


void ExpressionPrinter1::visit(Plus* expr){
	cout << "(";
	expr->left->accept(this); 
	cout << "+";
	expr->right->accept(this);
	cout << ")";
}

void ExpressionPrinter1::visit (Number* num){
	cout << num->number;
}

void ExpressionPrinter2::visit(Plus* expr){
	cout << "[";
	expr->left->accept(this); 
	cout << "+";
	expr->right->accept(this);
	cout << "]";
}

void ExpressionPrinter2::visit (Number* num){
	cout << num->number;
}

void NumberPrinter::visit (Number* num) {
	cout << "<" << num->number << ">" << endl;
}

void OnlyPlusPrinter::visit (Plus* expr) {
	expr->left->accept(this);
	cout << "+";
	expr->right->accept(this);
}