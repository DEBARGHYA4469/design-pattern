#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Subsystem libraries */ 

class Subsystem1 {
public:
	void foo1() const {};
	void foo2() const {}; 
};  

class Subsystem2 {
public:
	void bar1() const {};
	void bar2() const {}; 
};

/* Facade for something */
class Facade {
protected:
	Subsystem1* obj1; 
	Subsystem2* obj2; 
public:
	Facade () {
		obj1 = new Subsystem1();
		obj2 = new Subsystem2(); 
	}
	void job () {
		obj1->foo1(); 
		obj2->bar1();
		obj1->foo2();
		obj2->bar2(); 
	} 
}; 