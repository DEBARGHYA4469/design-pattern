#include "PrototypeFactory.hpp"

std::unique_ptr<Contact> EmployeeFactory::AuxOfficeEmployee(const std::string& name, const int& suite){
	Contact p("", new Address("123, East Dr", "London", 0));
	return newEmployee(name, suite, p);
}

std::unique_ptr<Contact> EmployeeFactory::HeadOfficeEmployee(const std::string& name, const int& suite){
	Contact p("", new Address("900, West Dr", "San Fr", 0));
	return newEmployee(name, suite, p);
}

/* Generic clone function, make a new object based on the prototype, edit the supplied values. [private, not seen by client]*/
std::unique_ptr<Contact> EmployeeFactory::newEmployee(const std::string& name, const int& suite, const Contact& prototype){
	auto result = std::make_unique<Contact> (prototype); 
	result->name = name; 
	result->address->suite = suite; 
	return result;
}