#include "bits/stdc++.h"

class IButton {
	public: 
		virtual void onClick () = 0;
};

class WinButton : public IButton {
	public:
		void onClick () override {
			std::cout << "You have clicked a win:button" << std::endl;
		}
}; 

class MacButton : public IButton {
	public:
		void onClick () override {
			std::cout << "You have clicked a mac:button" << std::endl;
		}
}; 

class ICheckBox {
	public: 
		virtual void onCheck () = 0;
};

class WinCheckBox : public ICheckBox {
	public:
		void onCheck () override {
			std::cout << "You have checked a win:checkbox" << std::endl;
		}
}; 

class MacCheckBox : public ICheckBox {
	public:
		void onCheck () override {
			std::cout << "You have clicked a mac:checkbox" << std::endl;
		}
}; 

class GUIFactory {
	public:
		virtual IButton* createButton () = 0;
		virtual ICheckBox* createCheckBox () = 0; 	
};

class WinFactory : public GUIFactory{
	IButton* createButton () override {
		return new WinButton(); 
	}
	ICheckBox* createCheckBox () override {
		return new WinCheckBox(); 
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