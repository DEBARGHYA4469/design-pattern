#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

#include "Tokenizer.hpp"

using namespace std;

/* Parser using a interpreter design pattern */

struct Context {
	map<string, double> var;
};

struct Expression {
	virtual ~Expression() = default;
	virtual double interpret(Context context) const = 0;	
};

/* Classes for the Token Type */
struct Number : Expression {
	double value;
	Number (double value) : value (value) {} 
	double interpret (Context) const override {
		return value;
	}
};

struct Variable : Expression {
	string name; 
	Variable (string name) : name (name) {} 
	double interpret (Context context) const override {
		return context.var[name]; 
	}
};

typedef unique_ptr<Expression> Expr;

struct BinaryOperation : Expression {
	char op; 	
	Expr left, right;
	BinaryOperation (char op, Expr left, Expr right) : op(op), left(std::move(left)), right (std::move(right)) { }
	double interpret (Context context) const override {
		double lval = left->interpret(context);
		double rval = right->interpret(context);
		switch (op) {
			case '+' : return lval + rval; 
			case '-' : return lval - rval;
			case '*' : return lval * rval;
			case '/' : return lval / rval;
			default: throw std::runtime_error("Unknown operator");
		}
	}
};

// Parser //

Expr parseExpression (const std::vector<Token>& tokens, size_t& pos);
Expr parseFactor (const std::vector<Token>& tokens, size_t& pos) {
	const Token& curr = tokens[pos]; 
	if (curr.type == TokenType::Number){
		double val = std::stod(curr.value);
		pos++;
		return make_unique<Number> (val);
	}
	else if (curr.type == TokenType::Variable){
		string name = curr.value; 
		++pos;
		return make_unique<Variable>(name);
	}
	else if (curr.type == TokenType::LParen){
		++pos;
		auto e = parseExpression(tokens, pos);
		if (tokens[pos].type == TokenType::RParen){
			++pos;
		}
		else {
			throw std::runtime_error ("Expected )");
		}
		return e;
	}
	else {
		throw std::runtime_error ("Unexpected token");
	}
}

Expr parseTerm  (const std::vector<Token>& tokens, size_t& pos) {
	auto left = parseFactor(tokens, pos);
	while (pos < tokens.size()) {
		const Token& curr = tokens[pos]; 
		if (curr.type == TokenType::Multiply || curr.type == TokenType::Divide) {
			char op = curr.value[0];
			++pos;
			auto right = parseFactor(tokens, pos);
			left =  make_unique<BinaryOperation> (op, std::move(left), std::move(right));
		}
		else {
			break;
		}
	}
	return left;
}

Expr parseExpression (const std::vector<Token>& tokens, size_t& pos) {
	auto left = parseTerm(tokens, pos); 
	while (pos < tokens.size()) {
		const Token& curr = tokens[pos]; 
		if (curr.type == TokenType::Plus || curr.type == TokenType::Minus) {
			char op = curr.value[0];
			++pos;
			auto right = parseTerm(tokens, pos);
			left = make_unique <BinaryOperation> (op, std::move(left), std::move(right));
		}
		else {
			break;
		}
	}
	return left; 
}

double interpret (const string& str, Context context) {
	vector<Token> tokens = tokenizer(str);
	size_t pos = 0; 
	auto e = parseExpression(tokens, pos);
	return e->interpret(context);
} 


