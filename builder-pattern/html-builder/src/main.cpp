#include "HtmlElementClass.hpp" 
#include "HtmlElementBuilderClass.hpp" 

int main () {
	
	// Client 
	//HtmlElementBuilder e = HtmlElement::build ("ul");
					//-> addchild ("li", "hello") 
					//-> addchild ("li", "world");
	
	HtmlElement e = *(HtmlElement::build("ul")
						-> append_child ("li", "hello")
						-> append_child ("li", "world")
					); 
	std::cout << e._str ();
	
	return 0;
}