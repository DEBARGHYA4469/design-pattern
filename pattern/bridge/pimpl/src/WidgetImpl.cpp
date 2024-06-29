#include "Widget.hpp" 

class Widget::WidgetImpl {
private: 
	std::string name; 
public:
	WidgetImpl (std::string &name) : name (name) {
		std::cout << "WidgetImpl :: constructor called." << std::endl;
	}
	~WidgetImpl() {
		std::cout << "WidgetImpl :: destructor called." << std::endl;
	}
	// Hidden functions from client  
	void gui_foo1 () const {
		std::cout << "WidgetImpl :: foo1 called." << std::endl;
	};
	void gui_foo2 () const {
		std::cout << "WidgetImpl :: foo2 called." << std::endl;
	};
	void gui_foo3 () const {
		std::cout << "WidgetImpl :: foo3 called." << std::endl;
	};
	void gui_foo4 () const {
		std::cout << "WidgetImpl :: foo4 called." << std::endl;
	};  
}; 

Widget::Widget (std::string name) : pImpl (std::make_unique<WidgetImpl> (name)){
	std::cout << "Widget :: constructor called." << std::endl;
} 
Widget::~Widget(){ std::cout << "Widget :: destructor called." << std::endl; }  	 
void Widget::show () const{  
	std::cout << "Widget :: show called." << std::endl;
	pImpl->gui_foo1(); 
}
void Widget::hide () const{  
	std::cout << "Widget :: hide called." << std::endl; 
	pImpl->gui_foo2();
}
void Widget::move () const{  
	std::cout << "Widget :: move called." << std::endl; 
	pImpl->gui_foo3();
}
