#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Code for a collectible-card game */

using namespace std;

struct Creature
{
	string name;
	int attack, defence;
	Creature (string name, int attack, int defence) : name (name), attack (attack), defence(defence) {} 
};

/* Interface for modifiers */
struct MagicSpell {
	MagicSpell* nxt = nullptr; // default : garbage
	Creature* c;
	MagicSpell (Creature* c) : c(c) {}
	virtual ~MagicSpell () = default;
	virtual void cast () {
		if (nxt) nxt -> cast();
	}
	void add (MagicSpell* m) {
		if (nxt) {
			nxt -> add (m);
		}
		else nxt = m;
	}
};

struct Fireball : MagicSpell {
	Fireball(Creature* c) : MagicSpell (c) {}
	virtual void cast () override {
		cout << "Fireball >>>" << endl;
		this->c->defence -= 3;
		MagicSpell::cast();
	}
};
struct Thunderstrike : MagicSpell {
	Thunderstrike (Creature* c) : MagicSpell (c) {}
	virtual void cast () override {
		cout << "Thunderstrike >>>" << endl;
		this->c->attack += 5;
		MagicSpell::cast();
	}
};
struct Sanctuary : MagicSpell {
	Sanctuary (Creature* c) : MagicSpell (c) {}
	virtual void cast () override {
		cout << "Sanctuary >>>" << endl;
		this->c->attack += 20;
		this->c->defence += 20;
		MagicSpell::cast();
	}
};

struct Annihilation : MagicSpell {
	Annihilation (Creature* c) : MagicSpell (c) {}
	virtual void cast () override {
		cout << "Annihilation >>>" << endl;
		this->c->attack = 0;
		this->c->defence = 0;
		//MagicSpell::cast(); creature dies here
	}
};

 