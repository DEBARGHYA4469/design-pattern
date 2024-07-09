#include "CCG.hpp" 

TEST (COR, test) {
	Creature* c = new Creature ("Goblin", 10, 10);

	MagicSpell* root = new MagicSpell(c); 
	
	Fireball* f = new Fireball (c); // 0, -3 
	Thunderstrike* t = new Thunderstrike (c); // 5, 0
	Sanctuary* s = new Sanctuary (c); // 20, 20 
	Annihilation* a = new Annihilation (c); // 20, 20 

	/* Chain of responsibility */
	root->add(f);
	root->add(t);
	root->add(a);
	root->add(s);
	/* Chain of responsibility */

	cout << "Before casting the magic spells ... " << endl;
	cout << c->name << " " << c->attack <<  " " << c->defence << endl;
	cout << "After casting the magic spells ... " << endl;
	root->cast();
	cout << c->name << " " << c->attack <<  " " << c->defence << endl;

}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}