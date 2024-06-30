#pragma once

#include "HtmlElementClass.hpp"

/* Builder class for HTML elements!  */

class HtmlElementBuilder {
	private: 
		HtmlElement m_root; 
	public:
		HtmlElementBuilder () = default;
		HtmlElementBuilder (std::string root_name);
		~HtmlElementBuilder (); 
		void set_root (std::string root_name);
		void Reset ();
		operator HtmlElement ();
		/* Fluent Builder Interface */
		HtmlElementBuilder* append_child (std::string child_name, std::string child_txt); 
		HtmlElement get_HtmlElement(); // producer function 
};