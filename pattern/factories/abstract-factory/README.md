Abstract Factory 

Abstract Factory provides a way to create a family of dependent products without specifying the 
concrete clases.

```cpp
#pragma once 
#include <iostream>

struct Button { virtual void click() = 0; };
struct CheckBox { virtual void check() = 0; };
struct GUIFactory {
	virtual Button* createButton() = 0; 
	virtual CheckBox* createCheckBox() = 0;
};

namespace MAC {
	struct Button : ::Button {
		void click() override { std::cout << "MAC_Button clicked" << std::endl; }
	};
	struct CheckBox : ::CheckBox {	
		void check() override { std::cout << "MAC_CheckBox clicked" << std::endl; }
	};
	struct GUIFactory : ::GUIFactory {
		GUIFactory() = default;
		Button* createButton() override { return new MAC::Button; }
		CheckBox* createCheckBox() override { return new MAC::CheckBox; }
	};
};

struct App {
	
	Button* button; 
	CheckBox* checkBox;
	App(GUIFactory* factory) {
		button = factory->createButton();
	}
	void run() {
		button->click();
		checkBox->check();
	}
};

int main() {
	MAC::GUIFactory factory;
	auto app = App(&factory);
	app.run();
}
```
