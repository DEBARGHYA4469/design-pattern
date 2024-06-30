#pragma once 
#include "bits/stdc++.h"

class HtmlElementBuilder;

/*
We do not want to allow client to change any of m_root, m_text, m_child directly from an HTML object. 
For example if client is allowed and they make m_child's child m_child's root, we run 
into infinite loop issue with _str method. 

Instead we delegate the HTML tree building construction to a HTMLBuilderClass. 
*/

class HtmlElement {
	private:
		std::string m_root;
		std::string m_text; 
		std::vector<HtmlElement> m_child; 
		constexpr static size_t m_indent_size = 4;
		friend class HtmlElementBuilder;
		HtmlElement (std::string m_root, std::string m_text);
	public:
		static std::unique_ptr <HtmlElementBuilder> build (std::string root);
		HtmlElement () = default;
		std::string _str (int32_t indent = 0);
		HtmlElement operator=(const std::unique_ptr <HtmlElementBuilder> &builder);
};

