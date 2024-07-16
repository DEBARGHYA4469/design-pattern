#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Strategy
{
	virtual void execute () = 0;
};

struct AddStrategy : Strategy{
	virtual void execute () override {
		cout << "We are inside add Strategy." << endl;
	}
};

struct MultiplyStrategy : Strategy{
	virtual void execute () override {
		cout << "We are inside multipy Strategy." << endl;
	}	
};

struct DynamicContext {
	Strategy* strategy;
	DynamicContext () = default;
	void set_strategy (Strategy* strategy){
		this->strategy = strategy;
	}
	void execute () {
		this->strategy->execute();
	}
};

template <typename S>
struct  StaticContext{
	S* strategy;
	StaticContext () {
		strategy = new S();
	}
	void execute () {
		strategy->execute();
	}
};

