#include "Command.hpp"


TEST (PhillipsTest, Command){
	PhillipsBulb* a = new PhillipsBulb();
	ConfigurableRemote* r = new ConfigurableRemote(a);
	
	r->OnBtn->setfcn([r](){
		r->smartbulb->on();
	});
	r->OnBtn->onPress();

	r->TwinkleBtn->setfcn([r](){
		for (int i=0;i<10;i++) {
			if (i&1) { r->smartbulb->light(); }
			else { r->smartbulb->dim(); }
		}
	});

	r->TwinkleBtn->onPress();
}

TEST (HavelsTest, Command){
	HavelsBulb* a = new HavelsBulb();
	ConfigurableRemote* r = new ConfigurableRemote(a);

	r->OnBtn->setfcn([r](){
		r->smartbulb->on();
	});
	r->OnBtn->onPress();

	r->TwinkleBtn->setfcn([r](){
		for (int i=0;i<10;i++) {
			if (i&1) { r->smartbulb->light(); }
			else { r->smartbulb->dim(); }
		}
	});
	
	r->TwinkleBtn->onPress();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}