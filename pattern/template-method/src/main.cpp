#include "Game.hpp" 

TEST (OrcsTest, test) {
	OrcsAI orca;
	orca.turn();
}

TEST (MonstersTest, test) {
	MonstersAI mons;
	mons.turn();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}