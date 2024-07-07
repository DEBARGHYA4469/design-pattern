#include "Player.hpp"
#include "Game.hpp"
#include "GameEvents.hpp"

void Player::joins (Game* game) {
	this->game = game;
	game->joins(this);
}

void Player::scores () {
	goals_scored++;
	Goal goal (*this);
	this->game->events(&goal);
	if (goals_scored % 3 == 0){
		Hattrick h (*this);
		this->game->events(&h);
 	}
}

void Player::tackles (string other) {
	game->tackle (this->name, other);
}

void Player::fouls (string other) {
	game->fouls (this->name, other);
}