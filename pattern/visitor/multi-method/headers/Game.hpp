#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* You to design a game where there will be unique interaction btw game characters. */

using namespace std;

struct Object; 
void attack (Object* a, Object* b);

struct Object {
	virtual ~Object () = default;
	virtual type_index type () const = 0;
	virtual void attack (Object* a) { ::attack(this, a); }
};  

template <typename T> struct ObjectImpl : Object {
	virtual type_index type () const override {
		return typeid(T);
	}
};

struct Rock : ObjectImpl<Rock> {};
struct Paper : ObjectImpl<Paper> {};
struct Scissors : ObjectImpl<Scissors> {};
struct MagicPaper : Paper { 
	virtual type_index type () const override {
		return typeid(MagicPaper);
	}
	virtual void attack (Object* a) { ::attack(this, a); } 
};





