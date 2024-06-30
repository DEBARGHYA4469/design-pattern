#include "PersonJobBuilder.hpp"

PersonJobBuilder* PersonJobBuilder::at (std::string at) { 
	this->person.company = at; 
	return this; 
}
PersonJobBuilder* PersonJobBuilder::designation (std::string designation){ 
	this->person.designation = designation; 
	return this; 
}	
PersonJobBuilder* PersonJobBuilder::income (std::string income) { 
	this->person.income= income; 
	return this; 
}