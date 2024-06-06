#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAddrBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main () {
	Person p = Person::create()
					   ->lives()
							-> name ("Deb")
							-> at ("45/A/1, KD road") 
							-> city ("Kolkata")
							-> pincode ("700061")
						->works()
							-> designation ("Programmer")
							-> at ("Company")
							-> income ("100")
			           ->get();
	p.show ();
	
	return 0; 
} 