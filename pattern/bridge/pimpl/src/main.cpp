#include "Widget.hpp" 

/* Implementation of Widget is hidden from client. All the gui functions etc. */

TEST (Widget, IsWorking) {
	Widget* w = new Widget("popup"); 
	w->show();
	w->move(); 
	w->hide(); 
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}