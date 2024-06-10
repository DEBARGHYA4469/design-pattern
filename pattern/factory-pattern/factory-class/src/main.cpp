#include "Point.hpp" 

int main () {
	
	
	auto p = Point::factory.Polar (3, 4); 
	// use this instead of Point::PointFactory::Polar 
	p.print (); 
	
	return 0;
}