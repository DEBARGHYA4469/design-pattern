#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

#include "ContainerSpec.hpp" 
#include "IteratorSpec.hpp"

/* List<Item> implements Container interface 
 *
 * */

using namespace std;

/* foreward declaration */
template <class Item> struct List;

/* Concrete ListIterator implements Iterator interface */

template <class Item> 
struct ListIterator : Iterator <Item> {
public:
	ListIterator (List<Item>* list) : list(list), idx(0) {}
    virtual void First () override;
    virtual bool hasNext () override;
    virtual void next () override;
    virtual void printcurr () override;
private:
	int idx; 
	List<Item>* list; 
};


/* Concrete List class implements Container interface */

template <class Item>
struct List : Container<Item> 
{	
	typedef ListIterator<Item> iterator; 
		
	virtual void insert (Item) override;
	virtual int count () const override;
	std::vector<Item> v;
};

/* ListIterator defintions */

template <class Item> void ListIterator<Item>::First () { idx = 0; } 

template <class Item> bool ListIterator<Item>::hasNext () { return idx < (list->v).size(); } 

template <class Item> void ListIterator<Item>::next () { idx++; } 

template <class Item> void ListIterator<Item>::printcurr () { cout << (list->v)[idx] << ","; } 

/* ListIterator defintions */


/* List definitions */

template <class Item> void List<Item>::insert (Item i) { v.push_back(i); } 

template <class Item> int List<Item>::count () const { return v.size(); } 

/* List definitions */
