#include "Player.hpp"
#include "Game.hpp"
#include "GameEvents.hpp"
#include "GameObservers.hpp"

TEST (EventBrokerTest, FootballGame){
	
	Game* LaLigaFinale = new Game();
	Referee* referee = new Referee (LaLigaFinale);
	FuboTV* fubotv = new FuboTV (LaLigaFinale);
	HattrickWatch *hattrickWatch = new HattrickWatch (LaLigaFinale);

	Player* Messi = new Player ("Messi");
	Player* Ronaldo = new Player ("Ronaldo");
	Player* Mbappe = new Player ("Mbappe");
	Player* Ramos = new Player ("Ramos");
	Messi->joins(LaLigaFinale);
	Ronaldo->joins(LaLigaFinale);
	Mbappe->joins(LaLigaFinale);
	Ramos->joins(LaLigaFinale);
	Messi->tackles("Ronaldo");
	Ramos->fouls("Messi");
	Mbappe->scores();
	Mbappe->scores();
	Messi->scores();
	Mbappe->scores();
	delete fubotv;
	delete referee;
	delete LaLigaFinale;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}