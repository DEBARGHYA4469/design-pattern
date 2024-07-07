#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include "boost/signals2.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "GameEvents.hpp"

using namespace std;
using namespace boost::signals2;

struct FuboTV {
	Game* game; 
	FuboTV (Game* game) : game (game) {
		game->events.connect (
			[=](Events* event) -> void {
				auto goalEvent = dynamic_cast <Goal* > (event);
				if (goalEvent) cout << "FuboTV [live] " << goalEvent->p.name << " scores a goal!!!" << endl;
			}
		);
	}	
};


struct Referee {
	Game* game; 
	Referee (Game* game) : game (game) {
		game->events.connect (
			[=](Events* event) -> void {
				auto foulEvent = dynamic_cast <Foul* > (event);
				if (foulEvent) { 
					cout << "Referee takes out yellow card, " << foulEvent->a.name << " fouls " << foulEvent->b.name << endl;
				}
			}
		);
	}	
};

struct HattrickWatch {
	Game* game; 
	HattrickWatch (Game* game) : game (game) {
		game->events.connect (
			[=](Events* event) -> void {
				auto hattrickEvent = dynamic_cast <Hattrick *> (event);
				if (hattrickEvent) { 
					cout << "WOW! " << hattrickEvent->a.name << " scores a hattrick!!!!" << endl;
				}
			}
		);
	}	
};