#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

/* Interface for ice-cream */
struct IceCream
{
 	virtual int cost () = 0;
 	virtual void show () = 0;   
};

struct VanillaIceCream : IceCream {
	virtual int cost () override {
		return 7;
	}
 	virtual void show ()  override {
 		cout << "Vanilla IceCream";
 	}  
};

struct IceCreamDecorator : IceCream {
	IceCream* i;
	IceCreamDecorator () = default;
	IceCreamDecorator (IceCream* i) : i(i) {}
	virtual int cost () override { return i->cost(); }
 	virtual void show ()  override { i->show(); }  
};

struct ChocolateChips : IceCreamDecorator {
	ChocolateChips (IceCream* i) : IceCreamDecorator(i) {} 
	virtual int cost () override { return i->cost() + 2; }
 	virtual void show ()  override { i->show(); cout << ", choco-chips sprinked"; } 
};

struct CaramelSyrup : IceCreamDecorator {
	CaramelSyrup (IceCream* i) : IceCreamDecorator(i) {} 
	virtual int cost () override { return i->cost() + 3; }
 	virtual void show ()  override { i->show(); cout << ", caramel syrup added"; } 
};

struct CrunchyWafers : IceCreamDecorator {
	CrunchyWafers (IceCream* i) : IceCreamDecorator(i) {} 
	virtual int cost () override { return i->cost() + 1; }
 	virtual void show ()  override { i->show(); cout << ", with crunchy wafers."; } 
};