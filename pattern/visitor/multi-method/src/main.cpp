#include "Game.hpp"
#include "Variant.hpp" 

TEST (GameTest, Rock_vs_Scissors) {
	Rock* a = new Rock ();
	Scissors* b = new Scissors ();
	a->attack (b); 
} 

TEST (GameTest, Rock_vs_Paper) {
	Rock* a = new Rock ();
	Paper* b = new Paper ();
	a->attack (b); 
} 

TEST (GameTest, Paper_vs_scissors) {
	Paper* a = new Paper ();
	Scissors* b = new Scissors ();
	a->attack (b); 
} 

TEST (GameTest, MagicPaper_vs_scissors) {
	MagicPaper* a = new MagicPaper ();
	Scissors* b = new Scissors ();
	a->attack (b); 
} 

TEST (VariantTest, test) {
	Variant_Visitor();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}