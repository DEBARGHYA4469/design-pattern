#include "Decorator.hpp" 

TEST (ColoredShape, BlueCircle){
	Circle *c = new Circle (2.0);
	ColoredShape* blueCircle = new ColoredShape (c, "blue");
	blueCircle -> draw (); 
} 

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}