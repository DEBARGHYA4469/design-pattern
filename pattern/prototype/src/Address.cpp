#include "Address.hpp"

Address::Address (const std::string& street, const std::string& city, const int suite) {
	this->street = street; 
	this->city = city; 
	this->suite = suite; 
} 

Address::Address (const Address& other){
	this->street = other.street;
	this->city = other.city;
	this->suite = other.suite;
}

std::ostream& operator << (std::ostream& os, const Address& a){
	return os << "[Street]: " << a.street << " [City]: " << a.city << " [Suite]: " << a.suite; 
}
