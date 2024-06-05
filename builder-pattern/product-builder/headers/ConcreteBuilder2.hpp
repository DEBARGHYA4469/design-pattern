#pragma once
#include "Product.hpp"
#include "ProductBuildSpec.hpp"

/* Company B will implement IProductBuilder interface in it's own way */

class ConcreteBuilder2 : public IProductBuilder {
	private: 
		Product *product; 
	
	public:
		ConcreteBuilder2 () {
			this->product = new Product();
		} 
		
		virtual ~ConcreteBuilder2 () {
			delete this->product; 
		}
		
		virtual void build_partA () override {
			product->parts.emplace_back ("Engine::Company2"); 
		}; // engine 
		
		virtual void build_partB () override {
			product->parts.emplace_back ("Propeller::Company2"); 
		};	// propeller
		
		virtual void build_partC () override {
			product->parts.emplace_back ("Controller_X::Company2"); 
			product->parts.emplace_back ("Controller_Y::Company2"); 
		}; // controller
		
		void Reset () {
			this->product = new Product();
		}		
		
		virtual Product* getProduct (std::string product_name) override{
			Product *tmp = this->product;
			tmp->product_name = product_name;
			this->Reset(); 
			return tmp;
		} 
};  