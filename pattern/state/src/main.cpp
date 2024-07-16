#include "State.hpp" 
#include "MediaPlayer.hpp"

TEST (MediaTest, test) {
	AudioPlayer* a = new AudioPlayer ();
	a->clickPlay();
	a->clickLock();
	a->clickLock();
	a->clickPlay();
	a->clickNext();
	a->clickLock();
} 

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}