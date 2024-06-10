#pragma once 
#include "GuiFactory.hpp"

class MacButton : public IButton {
	public:
		void onClick () override {
			std::cout << "You have clicked a mac:button" << std::endl;
		}
}; 

class MacCheckBox : public ICheckBox {
	public:
		void onCheck () override {
			std::cout << "You have clicked a mac:checkbox" << std::endl;
		}
}; 

class MacFactory : public GUIFactory{
	IButton* createButton () override {
		return new MacButton(); 
	}
	ICheckBox* createCheckBox () override {
		return new MacCheckBox(); 
	} 
};