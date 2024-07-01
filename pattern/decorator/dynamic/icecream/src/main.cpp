#include "IceCream.hpp" 

TEST (IceCreamTest, decorators) {
	IceCream* icecream = new VanillaIceCream();
	icecream = new ChocolateChips(icecream);
	icecream = new CaramelSyrup(icecream);
	icecream = new CrunchyWafers(icecream);
	cout << "You ordered:"; 
	icecream->show();
	cout << endl;
	cout << "Cost of the icecream is " << icecream->cost() << "$" << endl;	
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}