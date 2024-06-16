#pragma once

/* Interface for Product Build */

class IProductBuilder {
	public: 
		virtual ~IProductBuilder() {}
		virtual IProductBuilder* build_partA () = 0; // engine, pure virtual functions
		virtual IProductBuilder* build_partB () = 0;	// propeller, pure virtual functions
		virtual IProductBuilder* build_partC () = 0; // controller, pure virtual functions
		virtual Product* getProduct (std::string product_name) = 0; 
};