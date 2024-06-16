#pragma once 
#include "PersonBuilder.hpp"

class PersonJobBuilder : public PersonBuilderBase {
	public: 
		PersonJobBuilder (Person &person) : PersonBuilderBase (person) {}
		PersonJobBuilder* at (std::string); 
		PersonJobBuilder* designation (std::string);  
		PersonJobBuilder* income (std::string); 
};