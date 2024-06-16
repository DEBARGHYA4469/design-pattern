#include "Contact.hpp"

Contact::Contact () {
	this->name = ""; 
	this->address = nullptr;
}
Contact::~Contact () { 
	delete address;
}
Contact::Contact (const std::string &name, Address* address) {	
	this->name = name; 
	this->address = new Address(*address); 
}
Contact::Contact (const Contact& other) {
	this->name = other.name; 
	this->address = new Address (*other.address);
}
std::ostream& operator << (std::ostream& os, const Contact& c){
	return os << "name: " << c.name << "\nworks at : \n" << *c.address; 
}

Contact Contact::clone (const Contact& contact) {
	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << contact; 
	std::string s = oss.str();
	std::istringstream iss(s);
	boost::archive::text_iarchive ia(iss);
	Contact result; 
	ia >> result;
	return result;
} 