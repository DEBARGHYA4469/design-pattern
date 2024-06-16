#include "DialogFactory.hpp"

int main () {
	
	DialogUI* dialogui = new WebDialogUI(); 
	dialogui->render();
	
	std::cout << std::endl;
	
	DialogUI* dialogui2 = new WinDialogUI(); 
	dialogui2->render();
	
	return 0;
}
