#pragma once

#include "HtmlElementClass.hpp"

/* Builder class for HTML elements!  */

class HtmlElementBuilder {
	private: 
		HtmlElement m_root; 
	public:
		HtmlElementBuilder () = default;
		HtmlElementBuilder (std::string root_name);
		operator HtmlElement () {
			return m_root;
		}
		/* Fluent Builder Interface */
		HtmlElementBuilder* append_child (std::string child_name, std::string child_txt); 
		void test ();
};