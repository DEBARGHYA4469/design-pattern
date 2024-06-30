#include "PersonBuilder.hpp" 
#include "PersonAddrBuilder.hpp"
#include "PersonJobBuilder.hpp"

PersonBuilderBase::operator Person () {
	return std::move (person); 
}
Person PersonBuilderBase::get () const {
	return std::move(this->person);
}
	// builder facets 
PersonAddrBuilder* PersonBuilderBase::lives () {
	return new PersonAddrBuilder(person);
}
PersonJobBuilder* PersonBuilderBase::works () {
	return new PersonJobBuilder(person);
} 