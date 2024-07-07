#include "Player.hpp"
#include "Game.hpp"
#include "GameEvents.hpp"

void Game::joins (Player* p) {
	players.emplace_back (p);
	cout << "[Game log]: New player " << p->name << " joins the game" << endl;
}

void Game::tackle (string a, string b){
	Player *x, *y;
	for (Player* p: players) {
		if (p->name == a) x = p;
		if (p->name == b) y = p;
	}
	if (x && y) {
		cout << "[Game log]: " << x->name << " tackles " << y->name << endl;
	}
}

void Game::fouls (string a, string b){
	Player *x, *y;
	for (Player* p: players) {
		if (p->name == a) x = p;
		if (p->name == b) y = p;
	}
	if (x && y) {
		Foul foul (*x, *y);
		cout << "[Game log]: " << foul.a.name << " fouls " << foul.b.name << endl;
		this->events (&foul);
	}
}