#pragma once 
#include "bits/stdc++.h"

using namespace std;

struct A{ 
	virtual ~A() { 
		cout << "~A called" << endl;
	}
	virtual void foo () {
		cout << "A::foo called" << endl;
	}
};

struct B{ 
	~B() { 
		cout << "~B called" << endl;
	}
	virtual void foo () {
		cout << "B::foo called" << endl;
	}
};

struct C{ 
	~C() { 
		cout << "~C called" << endl;
	}
	virtual void foo () {
		cout << "C::foo called" << endl;
	}
};

struct D : B, A, C {
	~D() {
		cout << "~D called" << endl;
	}
	virtual void foo () {
		cout << "D::foo called" << endl;
	}
};