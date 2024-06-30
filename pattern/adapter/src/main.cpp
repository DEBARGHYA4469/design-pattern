#include "Adapter.hpp" 

class RoundHoleAdapterTest : public testing::Test {
public:
	RoundHoleAdapterTest () = default;
	RoundHole *roundhole; 
	void SetUp () override {
		roundhole = new RoundHole (5.0);
	}
	void TearDown () override {
		delete this->roundhole;
	} 
}; 

/* Test fixtures */ 

TEST_F (RoundHoleAdapterTest, smallRoundPeg) {
	RoundPeg* roundpeg = new RoundPeg (2.0); 
	EXPECT_EQ (roundhole->fits (roundpeg), true); 
} 

TEST_F (RoundHoleAdapterTest, largeRoundPeg) {
	RoundPeg* roundpeg = new RoundPeg (12.0); 
	EXPECT_NE (roundhole->fits (roundpeg), true); 
} 

TEST_F (RoundHoleAdapterTest, smallSquarePeg) {
	SquarePeg* squarepeg = new SquarePeg (1.0); 
	SquareToRoundPegAdapter *adaptedsquarepeg = new SquareToRoundPegAdapter(squarepeg);
	EXPECT_EQ (roundhole->fits (adaptedsquarepeg), true); 
} 


TEST_F (RoundHoleAdapterTest, largeSquarePeg) {
	SquarePeg* squarepeg = new SquarePeg (10.0); 
	SquareToRoundPegAdapter *adaptedsquarepeg = new SquareToRoundPegAdapter(squarepeg);
	EXPECT_NE (roundhole->fits (adaptedsquarepeg), true); 
} 

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}