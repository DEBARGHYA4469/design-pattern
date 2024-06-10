#include "HtmlElementClass.hpp" 
#include "HtmlElementBuilderClass.hpp"

std::unique_ptr<HtmlElementBuilder> HtmlElement::build (std::string root){
	return std::make_unique <HtmlElementBuilder> (root);
}

/*
writing m_root = m_root does not work, m_root inside a constructor refers to the params. 
you can use initializer's list instead
*/
HtmlElement::HtmlElement (std::string m_root, std::string m_text) {
	this->m_root = m_root;
	this->m_text = m_text;
} 

std::string HtmlElement::_str (int32_t indent){
	std::ostringstream oss; 
	int curr = indent * m_indent_size;
	auto spaces = [&](int32_t i) { return std::string (i, ' '); };
	
	/* pretty print */
	oss << spaces (curr) << "<" << m_root << ">" << std::endl;
	if (m_text.size()) {
		oss << spaces (curr + m_indent_size) << m_text << std::endl; 
	}
	
	for (auto &c : this->m_child) {
		oss << c._str(indent + 1);
	}
	oss << spaces (curr) << "</" << this->m_root << ">" << std::endl;
	/* pretty print */
	
	return oss.str();
}