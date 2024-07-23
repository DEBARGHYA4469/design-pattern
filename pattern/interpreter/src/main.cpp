#include "Tokenizer.hpp"
#include "Expression.hpp"

using namespace std;

TEST (ParserLogic, test) {
	string str = "2+(12/3+4)*3+3";
	Context context;
	int result = interpret(str, context);
	EXPECT_EQ(result, 29);
}

TEST (ParserLogicwithVar, test) {
	string str = "var1 * var2 / (var3 + 3)";
	Context context; 
	context.var["var1"] = 2;
	context.var["var2"] = 7;
	context.var["var3"] = 4;
	int result = interpret(str, context); 
	EXPECT_EQ (result, 2);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}