#include "Strategy.hpp" 

TEST (DynamicStrategy, Test) {
	AddStrategy* a = new AddStrategy();
	DynamicContext* context = new DynamicContext();
	context->set_strategy (a);
	context->execute();
}

TEST (StaticStrategy, Test) {
	StaticContext<MultiplyStrategy> *a = new StaticContext<MultiplyStrategy> ();
	a->execute();
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}