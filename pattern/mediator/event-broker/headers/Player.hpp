#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include "boost/signals2.hpp"


using namespace std;
using namespace boost::signals2;

struct Game;

struct Player {
	string name;
	Game* game;
	int goals_scored;
	Player (string name) : name (name) {}
	void joins (Game* game); 
	void scores ();
	void tackles (string other);
	void fouls (string other);
};
