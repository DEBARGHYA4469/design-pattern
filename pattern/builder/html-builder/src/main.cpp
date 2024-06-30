#include "HtmlElementClass.hpp" 
#include "HtmlElementBuilderClass.hpp" 

int main () {
	
	// Client 

	/* test : 1 */
	HtmlElement e = HtmlElement::build("ul")
						-> append_child("li", "hello")
						-> append_child("li", "world")
						-> get_HtmlElement(); 
						
	std::cout << e._str () << std::endl;
	
	/* test : 2 */
	
	auto builder = new HtmlElementBuilder (); 
	builder->set_root ("h1"); 
	builder->append_child ("h2", "This is h2 heading")
		   ->append_child ("h3", "This is h3 heading")
		   ->append_child ("h4", "This is h4 heading");
	HtmlElement P1 = builder->get_HtmlElement();
	std::cout << P1._str() << std::endl;
	
	/* test : 3 */
	
	builder->set_root ("p1"); 
	builder->append_child ("p2", "This is p2 paragraph")
		   ->append_child ("p3", "This is p3 paragraph")
		   ->append_child ("p4", "This is p4 paragraph");
	HtmlElement P2 = builder->get_HtmlElement();
	std::cout << P2._str() << std::endl;
	
	return 0;
}