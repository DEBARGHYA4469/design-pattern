#pragma once 
#include "Contact.hpp"
#include "Address.hpp"

class EmployeeFactory {
	public: 
		static std::unique_ptr<Contact> AuxOfficeEmployee(const std::string& name, const int& suite);
		static std::unique_ptr<Contact> HeadOfficeEmployee(const std::string& name, const int& suite);
	private:
		static std::unique_ptr<Contact> newEmployee(const std::string& name, const int& suite, const Contact& c);
}; 

