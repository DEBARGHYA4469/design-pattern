#include "CyclicVisitor.hpp"
#include "Shape.hpp" 

void Visitor::visit (Circle* c) {
	cout << "I visited circle, calling circle draw. " << endl;
	c->draw();
}

void Visitor::visit (Square* s) {
	cout << "I visited square, calling square draw. " << endl;
	s->draw();
}


void DifferentVisitor::visit (Circle* c) {
	cout << "Different I visited circle, calling circle draw. " << endl;
	c->draw();
}

void DifferentVisitor::visit (Square* s) {
	cout << "Different I visited square, calling square draw. " << endl;
	s->draw();
}
