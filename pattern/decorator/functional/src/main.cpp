#include "Logger.hpp"
#include "Timing.hpp" 

int Add (int a, int b) { return a+b; }

TEST (LoggerTest, test) {
	auto addLogged = logging_decorator(Add);
	std::cout << addLogged(2,3) << std::endl; 
}

TEST (TimingTest, test) {
	auto addTimed = timing_decorator(Add);
	std::cout << addTimed(2,3) << std::endl; 
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}