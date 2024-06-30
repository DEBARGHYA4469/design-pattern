#include "Flyweight.hpp" 

void AddPoliceToDatabase () {
	Flyweight ff ({{"Car1" , "X1", "Black"}, {"Car2" , "X2", "Green"}, {"Car3" , "X3", "Red"}});
	Police p1 (ff, "John Doe", "Car4", "X3", "Orange");
	Police p3 (ff, "Jeff Doe", "Car2", "X2", "Green");
	Police p4 (ff, "Jack Doe", "Car2", "X2", "Green");
	cout << endl;
	cout << "Car::Address for p1: " << p1.c << endl;
	cout << "Car::Address for p3: " << p3.c << endl;
	cout << "Car::Address for p4: " << p4.c << endl;
	ASSERT_EQ (p3.c, p4.c);
	ASSERT_NE (p1.c, p4.c);
	ff.show_cars(); 
} 

