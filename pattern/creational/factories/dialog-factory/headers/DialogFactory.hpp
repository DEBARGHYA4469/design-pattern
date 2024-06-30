#include "bits/stdc++.h"

/* Interface of a button */
class IButton {
	public:
		virtual void render () = 0; 
		virtual void onClick (std::string) = 0; 
};

class WinButton : public IButton {
	public:
		WinButton () = default;
		void render () override {
			std::cout << "Windows button is rendered" << std::endl;
		}; 
		void onClick (std::string message) override {
			std::cout << "Message (Win) : " << message << std::endl;
		}; 
}; 

class WebButton : public IButton {
	public:
		WebButton () = default;
		void render () override {
			std::cout << "Web button is rendered" << std::endl;
		}; 
		void onClick (std::string message) override {
			std::cout << "Message (Web) : " << message << std::endl;
		}
}; 

class DialogUI {
	private:
		IButton* okButton; 
	public: 
		virtual IButton* createButton () {
			return this->createButton();
		} /* Factory method */
		void render () {
			okButton = this->createButton ();
			okButton->onClick ("Alert!");
			okButton->render(); 
		} 
}; 

/* Concrete Factory */
class WinDialogUI : public DialogUI {
	public: 
		IButton* createButton () override {
			return new WinButton (); 
		}
};

/* Concrete Factory */
class WebDialogUI : public DialogUI {
	public: 
		IButton* createButton () override {
			return new WebButton (); 
		}
};
