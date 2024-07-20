#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Item;

template <class Item> 
struct Iterator {
	virtual ~Iterator () = default; 
	virtual void First () = 0; 
	virtual bool hasNext () = 0;
	virtual void next () = 0;
	virtual void printcurr () = 0;
}; 
