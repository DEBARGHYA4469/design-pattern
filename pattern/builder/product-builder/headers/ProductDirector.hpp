#pragma once
#include "Product.hpp"
#include "ProductBuildSpec.hpp"

class Director {
	private: 
		IProductBuilder* builder;
	public: 
		Director (IProductBuilder* builder) : builder (builder) {}
		~Director () {
			//delete builder;
		} 
		void set_builder (IProductBuilder* builder) { 
			this->builder = builder; 
		}
		Product* get_full_build_product (std::string product_name) {
			std::cout << "Building " << product_name << "..." << std::endl;
			builder->build_partA()
				   ->build_partB()
				   ->build_partC();
			return builder->getProduct(product_name);
		}
		
		Product* get_minimal_viable_product (std::string product_name) {
			std::cout << "Building MVP::" << product_name << "..." << std::endl;
			builder->build_partA()
				   ->build_partB();
			return builder->getProduct("MVP::"+product_name);
		}
		
}; 