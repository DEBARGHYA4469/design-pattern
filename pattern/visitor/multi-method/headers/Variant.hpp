#pragma once 
#include "bits/stdc++.h"

struct Printer {
	void operator ()(string a) { cout << "String:" << a << endl; }
	void operator ()(int a) { cout << "Integer:" << a << endl; }
};

void Variant_Visitor (){
	std::variant <string, int> a, b;
	a = "Hello";
	b = 120;
	Printer p;
	std::visit (p, a);
	std::visit (p, b);
}