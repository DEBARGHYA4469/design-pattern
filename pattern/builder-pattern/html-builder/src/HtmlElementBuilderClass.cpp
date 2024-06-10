#include "HtmlElementClass.hpp"
#include "HtmlElementBuilderClass.hpp"
 
HtmlElementBuilder::HtmlElementBuilder (std::string root_name) {
	m_root.m_root = root_name; 
}

// don't call delete (this), this calls infinite destructors -> stack overflow 
HtmlElementBuilder::~HtmlElementBuilder () {
}

HtmlElementBuilder* HtmlElementBuilder::append_child (std::string child_name, std::string child_txt) {
	HtmlElement child(child_name, child_txt);
	m_root.m_child.emplace_back (child);
	return this; 
}

void HtmlElementBuilder::Reset() {
	this->m_root = HtmlElement ();
} 

HtmlElementBuilder::operator HtmlElement () {
	return m_root;
}

// produce the object and clean/release the builder for next construction
HtmlElement HtmlElementBuilder::get_HtmlElement(){
	HtmlElement tmp = m_root; 
	this->Reset (); 
	return tmp;
}

void HtmlElementBuilder::set_root (std::string root_name){
	this->m_root.m_root = root_name;
}