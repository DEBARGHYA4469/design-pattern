#include "HtmlElementBuilderClass.hpp"
 
HtmlElementBuilder::HtmlElementBuilder (std::string root_name) {
	m_root.m_root = root_name; 
}

HtmlElementBuilder* HtmlElementBuilder::append_child (std::string child_name, std::string child_txt) {
	m_root.m_child.emplace_back (HtmlElement(child_name, child_txt)); 
	return this; 
}

void HtmlElementBuilder::test (){
	HtmlElement h; 
	h.m_root = "p";
	h.m_text = "hello";
	
	HtmlElement c1; 
	c1.m_root = "h1";
	c1.m_text = "hello";
	
	HtmlElement c2; 
	c2.m_root = "h2";
	c2.m_text = "hello";

	h.m_child = {c1, c2};
	
	std::cout << h._str() << std::endl;
}