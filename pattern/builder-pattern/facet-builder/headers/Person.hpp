#pragma once 
#include "bits/stdc++.h"

class PersonBuilder;

class Person {
	private: 
		std::string name, street, city, pincode; 
		std::string designation, company, income; 
	public:
		void show () const;
		static std::unique_ptr<PersonBuilder> create ();
		friend class PersonBuilder;
		friend class PersonBuilderBase;
		friend class PersonAddrBuilder;
		friend class PersonJobBuilder;
}; 