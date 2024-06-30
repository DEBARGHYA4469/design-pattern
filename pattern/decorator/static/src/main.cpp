#include "Decorator.hpp" 


TEST (DecoratorTest, MixinTest) {
	ColoredShape<Circle> bc ("blue", 2);
	std::cout << bc.draw() << std::endl;
	std::cout << bc._color() << std::endl;
	std::cout << bc._R() << std::endl;


	TransparentShape<ColoredShape<Square>> trs ("0.8", "red", 3);
	std::cout << trs.draw() << std::endl;
	std::cout << trs._width() << std::endl;
	std::cout << trs._color() << std::endl;
	std::cout << trs._transparency() << std::endl; 
} 

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}