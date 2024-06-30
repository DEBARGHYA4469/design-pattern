#include "Flyweight.hpp" 

TEST (Flyweight, ILtest) {
	Flyweight ff ({{"BMW", "X3", "Beize"}, {"Suzuki", "i10", "Blue"}, {"Chevrolet", "AR2", "Black"}});
	ff.show_cars();
	ff.checkout ({"Maruti", "R2", "Red"});
	ff.checkout ({"Maruti", "R2", "Red"});
	ff.checkout ({"Maruti", "R2", "Red"});
	ff.checkout ({"Maruti", "R2", "Red"});
	ff.show_cars();
	AddPoliceToDatabase();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}