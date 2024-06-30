#include "Contact.hpp"
#include "Address.hpp"
#include "PrototypeFactory.hpp" 

int main () {
	
	/*auto rob = EmployeeFactory::AuxOfficeEmployee("Rob", 9);
	std::cout << *rob << std::endl;
	auto charles = EmployeeFactory::HeadOfficeEmployee("Charles", 2);
	std::cout << *charles << std::endl;*/
	
	/*
		Above approach is okay, but if you have multiple member pointer variables you have to make sure to deep copy everything. 
		Alternative approach for such class, is to use a serializer.
		<<Prototype Factory with Boost serialization>>
	*/
	const Contact sample_head_office_emp("", new Address("123, East Dr", "London", 0));
	const Contact sample_aux_office_emp("", new Address("900, West Dr", "San Fr", 0));
	Contact tom = Contact::clone (sample_head_office_emp);

	tom.name = "Tom";
	tom.address->suite = 1;
	std::cout << tom << std::endl << std::endl;
	
	Contact jerry = Contact::clone (sample_head_office_emp); 
	jerry.name = "Jerry";
	jerry.address->suite = 2;
	std::cout << jerry << std::endl << std::endl;
	
	Contact spike = Contact::clone (sample_aux_office_emp); 	
	spike.name = "Spike";
	spike.address->suite = 3;
	std::cout << spike << std::endl << std::endl;
	
	return 0;
}