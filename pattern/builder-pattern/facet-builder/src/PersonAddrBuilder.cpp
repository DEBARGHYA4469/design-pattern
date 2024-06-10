#include "PersonAddrBuilder.hpp"

PersonAddrBuilder* PersonAddrBuilder::name (std::string name) { 
	this->person.name = name;
	return this; 
}
PersonAddrBuilder* PersonAddrBuilder::at (std::string at) { 
	this->person.street = at; 
	return this; 
}
PersonAddrBuilder* PersonAddrBuilder::city (std::string city) { 
	this->person.city = city;
	return this; 
}		
PersonAddrBuilder* PersonAddrBuilder::pincode (std::string pincode) { 
	this->person.pincode = pincode;
	return this; 
}