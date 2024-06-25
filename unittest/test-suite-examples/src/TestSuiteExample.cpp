#include "TestSuiteExample.hpp"

TEST(TestName1, SubTest_1){
	ASSERT_FALSE(1==2);
}

TEST(TestName2, SubTest_2){
	ASSERT_TRUE(1==1);
}

TEST(TestName1, SubTest_2){
	EXPECT_STRCASEEQ("Hello", "HELLO");
}

TEST(TestName2, SubTest_1){
	ASSERT_EQ(1, 1);
}

class MyClass {
	private: 
		std::string var; 
	public:
		MyClass (std::string var) : var(var) { } 
		std::string get_var () const { return var; }
		void set_var (std::string var) { this->var = var; }
};

TEST(MyClassTest, getter) {
	MyClass mc ("root");
	std::string var = mc.get_var(); 
	EXPECT_STREQ(var.c_str(), "root");
}

TEST(MyClassTest, setter) {
	MyClass mc ("root");
	mc.set_var ("user");
	std::string var = mc.get_var(); 
	ASSERT_STREQ(var.c_str(), "user");
}