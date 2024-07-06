#include "Expression.hpp"
#include "AcyclicVisitor.hpp"

void Plus::accept (BaseVisitor* v) {
	if(auto u = dynamic_cast<Visitor<Plus>*> (v)) // slice of other things. 
		u->visit(this);
	else 
		cout << "_";
}

void Number::accept (BaseVisitor* v) {
	if(auto u = dynamic_cast<Visitor<Number>*> (v)) // slice of other things. 
		u->visit(this);
	else 
		cout << "_";
}