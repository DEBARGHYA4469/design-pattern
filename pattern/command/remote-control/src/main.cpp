#include "Command.hpp"


TEST (PhillipsTest, Command){
	PhillipsBulb* a = new PhillipsBulb();
	ConfigurableRemote* r = new ConfigurableRemote(a);
	r->OnBtn();
	r->OffBtn();
	r->OnBtn();
	r->TwinkleBtn();
}

TEST (HavelsTest, Command){
	HavelsBulb* a = new HavelsBulb();
	ConfigurableRemote* r = new ConfigurableRemote(a);
	r->OnBtn();
	r->OffBtn();
	r->OnBtn();
	r->TwinkleBtn();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}