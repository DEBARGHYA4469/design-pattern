#include "AbstractFactory.hpp" 

/* Game acts as a client */
class QuizApp {
	IButton* button; /* depends on interface of button */
	ICheckBox* checkbox;
	public:
		QuizApp (GUIFactory* factory) { /* button and checkbox may be related to a OS, hence delegate the work to a factory*/
			button = factory->createButton();
			checkbox = factory->createCheckBox(); 			
		}
		void onClick () {
			button->onClick(); 
		}
		void onCheck () {
			checkbox->onCheck(); 
		}
			
};

int main () {
	
	/* client */
	QuizApp app(new WinFactory());
	app.onClick();
	app.onCheck();
	
	std::cout << std::endl;
	
	QuizApp app2(new MacFactory());
	app2.onClick();
	app2.onCheck();
	
	return 0;
}