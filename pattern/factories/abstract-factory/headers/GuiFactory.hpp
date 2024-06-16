#pragma once 
#include "bits/stdc++.h"

class IButton {
	public: 
		virtual void onClick () = 0;
};

class ICheckBox {
	public: 
		virtual void onCheck () = 0;
};

class GUIFactory {
	public:
		virtual IButton* createButton () = 0;
		virtual ICheckBox* createCheckBox () = 0; 	
};

/* Dependency Inversion : Any new GUIComponent needs to extend GuiFactory and GuiFactory remains same! */
