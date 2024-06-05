#pragma once
#include "Product.hpp"
#include "ProductBuildSpec.hpp"

/* Company A will implement IProductBuilder interface in it's own way */

class ConcreteBuilder1 : public IProductBuilder {
	private: 
		Product *product; 
	
	public:
		ConcreteBuilder1 () {
			this->product = new Product();
		}

		virtual ~ConcreteBuilder1 () {
			delete this->product; 
		}		
		
		virtual void build_partA () override {
			product->parts.emplace_back ("Engine::Company1"); 
		}; // engine 
		
		virtual void build_partB () override {
			product->parts.emplace_back ("Propeller::Company1"); 
		};	// propeller
		
		virtual void build_partC () override {
			product->parts.emplace_back ("Controller::Company1"); 
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