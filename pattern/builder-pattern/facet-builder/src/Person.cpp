#include "Person.hpp" 
#include "PersonBuilder.hpp"

std::unique_ptr<PersonBuilder> Person::create  () {
	return std::make_unique<PersonBuilder> (); 
}


void Person::show () const {
	std::cout << "Your person is:" << std::endl;
	std::cout << "Address: " << std::endl;
	std::cout << "	name: " << name <<  std::endl;
	std::cout << "	at: " << street <<  std::endl;
	std::cout << "	city: " << city <<  std::endl;
	std::cout << "	pincode: " << pincode <<  std::endl;
	std::cout << "Work Information: " << std::endl;
	std::cout << "	at: " << company <<  std::endl;
	std::cout << "	designation: " << designation <<  std::endl;
	std::cout << "	income: " << income <<  std::endl;
}
