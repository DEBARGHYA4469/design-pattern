#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

enum class TokenType {
		Number,
		Variable,
		Plus,
		Minus,
		Multiply,
		Divide, 
		LParen, 
		RParen,
		End
};

struct Token {
	TokenType type; 
	string value;
}; 

std::vector<Token> tokenizer (const std::string& str) {
	std::vector<Token> tokens;
	size_t pos = 0;
	while (pos < str.size()) {
		char curr = str[pos];
		if (std::isspace(curr)) ++pos;
		else if (std::isdigit(curr)){
			std::string number; 
			while (pos < str.size() && std::isdigit(str[pos])) 
				number += str[pos++];
			tokens.push_back({
				TokenType::Number,
				number
			});
		}
		else if (std::isalpha(curr)) {
			string variable;
			while (pos < str.size() && std::isalnum(str[pos])){
				variable += str[pos++];
			}
			tokens.push_back({
				TokenType::Variable,
				variable
			});		
		} else {
			switch (curr) {
				case '+': tokens.push_back ({ TokenType::Plus, "+"}); break;
				case '-': tokens.push_back ({ TokenType::Minus, "-"}); break;
				case '/': tokens.push_back ({ TokenType::Divide, "/"}); break;
				case '*': tokens.push_back ({ TokenType::Multiply, "*"}); break;
				case '(': tokens.push_back ({ TokenType::LParen, "("}); break;
				case ')': tokens.push_back ({ TokenType::RParen, ")"}); break;
				default: throw std::runtime_error("Unexpected character");
			}
			++pos;
		}
	}
	tokens.push_back ({TokenType::End, ""});
	return tokens;
}