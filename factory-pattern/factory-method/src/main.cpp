#include "Point.hpp" 

int main () {
	Point p = Point::Cartesian (2, 3);
	p.print();
	Point q = Point::Polar (1,2);
	q.print();
	return 0;
}