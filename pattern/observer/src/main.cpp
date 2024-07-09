#include "Observer.hpp" 
#include "Person.hpp"

TEST (PersonTest, observers) {
	Person ram ("Ram", 12, 130);
	HeightTracker* h = new HeightTracker ();
	AgeTracker* a = new AgeTracker ();
	ram.subscribe (h);
	ram.subscribe (a);
	ram.set_height(133);
	ram.set_height(145);
	ram.set_height(156);
	ram.set_age(13);
	ram.set_age(14);
	ram.set_age(16);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}