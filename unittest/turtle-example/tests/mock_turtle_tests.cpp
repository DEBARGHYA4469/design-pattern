#include "mock_turtle.h" 
#include "painter.h" 
#include "gtest/gtest.h"

using ::testing::AtLeast;

// Painter Test Suite 
TEST (PainterTest, CanDrawSomething) {
	MockTurtle turtle;
	EXPECT_CALL (turtle, PenDown())
		.Times (AtLeast (1));
	ASSERT_EQ(1,1);
	Painter* painter = new Painter(&turtle);
	painter->DrawCircle(1,2,3);
	delete painter;
} 

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
