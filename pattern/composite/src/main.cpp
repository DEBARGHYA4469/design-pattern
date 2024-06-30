#include "Composite.hpp" 

TEST (CompositeGUITest, test) {
	CompoundGraphics G; 
	G.add (new Dot(1,2));
	G.add (new Circle(2,3,1));
	G.draw ();
	G.move (100,100);
	G.draw (); 
} 

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}