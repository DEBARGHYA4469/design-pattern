#include "TestFixtureExample.hpp"

template<typename T> 
struct Stack {
	std::vector<T> v; 
	void push (T val) { v.emplace_back(val); }
	size_t get_size () { return v.size(); }
	T pop () { 
		if (!get_size()) return -1; 
		T top = v.back();
		v.pop_back();
		return top;
	} 
}; 

// SetUp and TearDown test code 
struct StackIntegerTest : public testing::Test {
	Stack<int> *s;
	StackIntegerTest () { s = new Stack<int>(); }
	void SetUp () override {
		s->push(1);
		s->push(2);
		s->push(3);
		s->push(4);
		s->push(5);
	}
	void TearDown () override {
		delete this->s; 
	} 
}; 

// Test Fixture : 1
TEST_F (StackIntegerTest, PopTest) {
	for (int i=5;i>0;i--) {
		ASSERT_EQ (i, s->pop());
	}
} 

// Test Fixture : 2
TEST_F (StackIntegerTest, UnderflowTest) {
	for (int i=5;i>0;i--) s->pop();
	ASSERT_EQ (-1, s->pop());
	ASSERT_EQ (-1, s->pop());
} 