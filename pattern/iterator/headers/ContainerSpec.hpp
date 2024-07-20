#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

#include "IteratorSpec.hpp"
using namespace std;

/*
 * Container class: Aka aggregate. 
 * Contains list of items. 
 * Supports operations like : 
 * 	+ insert 
 * 	+ count
 * 	+ createIterator 
 * */

struct Item;

template <class Item> 
struct Container
{
	virtual ~Container () = default;
	virtual void insert (Item) = 0;
	virtual int count () const = 0;
};
