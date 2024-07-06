#include "Game.hpp" 


void rock_paper () { cout << "Paper wins! Rock loses" << endl; }
void rock_scissors () { cout << "Rock wins! Scissors loses" << endl; }
void scissors_paper () { cout << "Scissors wins! Paper loses" << endl; } 
void magicpaper () { cout << "MagicPaper always wins!" << endl; }


map <pair<type_index,type_index>, void(*)(void)> outcomes{
	{{typeid(Rock), typeid(Paper)}, rock_paper},
	{{typeid(Scissors), typeid(Paper)}, scissors_paper},
	{{typeid(Rock), typeid(Scissors)}, rock_scissors},
	{{typeid(MagicPaper), typeid(Paper)}, magicpaper},
	{{typeid(MagicPaper), typeid(Rock)}, magicpaper},
	{{typeid(MagicPaper), typeid(Scissors)}, magicpaper}
};

void attack (Object* a, Object *b){
	auto it = outcomes.find ({a->type(), b->type()});
	if (it == outcomes.end()) {
		it = outcomes.find ({b->type(), a->type()});
		if (it == outcomes.end()) {
			cout << "Draw!" << endl;
		}
	}
	it->second();
}
