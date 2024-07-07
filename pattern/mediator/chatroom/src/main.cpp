#include "Person.hpp"
#include "ChatRoom.hpp"

TEST (ChatRoomTest, mediator) {
	ChatRoom* c = new ChatRoom ();
	Person* virat = new Person ("Virat");
	Person* rohit = new Person ("Rohit");
	Person* bumrah = new Person ("Bumrah");
	c->join(virat);
	c->join(rohit);
	virat->say ("If we win the toss, let's bat first today.");
	rohit->private_message ("Virat", "Don't reveal that until toss!");
	c->join(bumrah);
	virat->say ("Hi Jaspreet!");
	bumrah->say ("Hi Guys");
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}