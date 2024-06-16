#pragma once 
#include "Person.hpp"

class PersonAddrBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
	protected:
		Person& person; 
		PersonBuilderBase () = default;
		PersonBuilderBase (Person &person) : person (person) {}
		operator Person ();
		/* builder facets */
	public:
		Person get () const;
		PersonAddrBuilder* lives ();
		PersonJobBuilder* works ();
};

class PersonBuilder : public PersonBuilderBase{
	protected: 
		Person person;
	public: 
		PersonBuilder () : PersonBuilderBase (person)  {}
}; 