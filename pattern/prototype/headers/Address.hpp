#pragma once 
#include "bits/stdc++.h" 
#include <boost/serialization/serialization.hpp> 
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Address {
	public: 
		std::string street; 
		std::string city; 
		int suite; 
	public:
		Address () = default;
		Address (const std::string& street, const std::string& city, const int suite);
		Address (const Address& other);
		friend std::ostream& operator << (std::ostream& os, const Address& a);
		friend class boost::serialization::access;
		template <class archive> 
		void serialize (archive &ar, const unsigned version){
			ar & street; 
			ar & city;
			ar & suite;
		}
}; 