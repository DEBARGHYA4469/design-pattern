#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include "boost/signals2.hpp"
#include "Player.hpp"

using namespace std;
using namespace boost::signals2;

struct Events {
	virtual ~Events () = default;
};

struct Goal : Events
{
	Player p;
	Goal (Player p) : p(p) {}	
};

struct Foul : Events
{
	Player a, b;
	Foul (Player a, Player b) : a(a), b(b) {}
};

struct Hattrick : Events
{
	Player a;
	Hattrick (Player a) : a(a) {}	
};