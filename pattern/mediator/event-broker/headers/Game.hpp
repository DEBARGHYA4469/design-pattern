#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include "boost/signals2.hpp"
#include "GameEvents.hpp"


using namespace std;

struct Game {	
	boost::signals2::signal<void(Events*)> events;
	vector<Player*> players;
	void joins (Player* p);
	void tackle (string a, string b);
	void fouls (string a, string b);
};
