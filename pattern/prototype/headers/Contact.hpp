#pragma once 
#include "Address.hpp" 
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class EmployeeFactory;

class Contact {
	public: 
		std::string name; 
		Address* address;
	public: 		
		Contact ();
		~Contact ();
		Contact (const std::string &name, Address* address);
		Contact (const Contact& other);
		friend std::ostream& operator << (std::ostream& os, const Contact& c);
		static Contact clone (const Contact& contact);  
	private: 
		friend class EmployeeFactory;
		friend class boost::serialization::access;
		template <class archive> 
		void serialize (archive &ar, const unsigned version){
			ar & name; 
			ar & address;
		}
};