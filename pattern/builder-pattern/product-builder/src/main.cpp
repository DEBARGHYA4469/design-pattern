#include "ConcreteBuilder1.hpp" 
#include "ConcreteBuilder2.hpp" 
#include "ProductDirector.hpp"

int main () {

	// client code 
	
	/* lease two builders */
	ConcreteBuilder1 *builder = new ConcreteBuilder1; 
	ConcreteBuilder2 *builder2 = new ConcreteBuilder2;
	
	/* Hire a director */
	Director* director = new Director (builder);
	
	/* Build plane : 1 */
	director->get_full_build_product("Thunderjet")->show();
	/* Build plane : 2 */
	director->get_full_build_product("Warhawk")->show();
	
	/* Build plane : 3 */
	director->set_builder (builder2); 
	director->get_minimal_viable_product("Aardvark")->show(); 
	
	return 0;
}