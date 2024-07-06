//#include "CyclicVisitor.hpp" 
//#include "Shape.hpp"
#include "gtest/gtest.h"
#include "AcyclicVisitor.hpp"
#include "Expression.hpp"
#include "Dynamic.hpp"

/*TEST (CyclicVisitorTest, test) {
	Shape* s = new Circle (); 
	Shape* t = new Square (); 

	Visitor* v = new Visitor (); 
	cout << "Calling visitor for circle obj:" << endl;
	s->accept (v);
	cout << "Calling visitor for square obj:" << endl;
	t->accept (v);
}

TEST (CyclicAnotherVisitorTest, test) {
	Shape* s = new Circle (); 
	Shape* t = new Square (); 

	Visitor* v = new DifferentVisitor (); 
	cout << "Calling different visitor for circle obj:" << endl;
	s->accept (v);
	cout << "Calling different visitor for square obj:" << endl;
	t->accept (v);
}*/

struct R {};

TEST (DynamicCastTest, Basic) {
	A* a = new D();
	//a->foo();

	B* b = dynamic_cast<B*>(a);
	b->foo();

	delete a;
}


class ExpressionTest : public testing::Test {
public:
	Expression* expr;
	Expression* numexpr;
	ExpressionTest () {
		expr = new Plus(
			new Number (1), 
			new Plus (
					new Plus (
						new Number (2),
						new Number (3)
					),
					new Number (4)
				)
		);
		numexpr = new Number (777);
	}
	void SetUp () override {

	}
	void TearDown () override {
		delete expr;
	}
};

TEST_F (ExpressionTest, acyclic1) {
	ExpressionPrinter1* ep = new ExpressionPrinter1();
	expr->accept(ep);  
}

TEST_F (ExpressionTest, acyclic2) {
	ExpressionPrinter2* ep = new ExpressionPrinter2();
	expr->accept(ep);  
}

TEST_F (ExpressionTest, subvisitor){
	NumberPrinter* np = new NumberPrinter();
	numexpr->accept(np);
}

TEST_F (ExpressionTest, onlyplusskeleton) {
	OnlyPlusPrinter* ep = new OnlyPlusPrinter();
	expr->accept(ep);  
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}