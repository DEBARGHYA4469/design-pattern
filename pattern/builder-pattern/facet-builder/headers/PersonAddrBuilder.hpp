#pragma once
#include "PersonBuilder.hpp" 

class PersonAddrBuilder : public PersonBuilderBase {
	public: 
		PersonAddrBuilder (Person &person) : PersonBuilderBase (person) {}
		PersonAddrBuilder* name (std::string name);
		PersonAddrBuilder* at (std::string); 
		PersonAddrBuilder* city (std::string); 		
		PersonAddrBuilder* pincode (std::string);
};