#pragma once 
#include "GuiFactory.hpp"

class WinButton : public IButton {
	public:
		void onClick () override {
			std::cout << "You have clicked a win:button" << std::endl;
		}
}; 

class WinCheckBox : public ICheckBox {
	public:
		void onCheck () override {
			std::cout << "You have checked a win:checkbox" << std::endl;
		}
}; 


class WinFactory : public GUIFactory{
	IButton* createButton () override {
		return new WinButton(); 
	}
	ICheckBox* createCheckBox () override {
		return new WinCheckBox(); 
	} 
};