#pragma once

/* Interface for Product Build */

class IProductBuilder {
	public: 
		virtual ~IProductBuilder() {}
		virtual void build_partA () = 0; // engine, pure virtual functions
		virtual void build_partB () = 0;	// propeller, pure virtual functions
		virtual void build_partC () = 0; // controller, pure virtual functions
		virtual Product* getProduct (std::string product_name) = 0; 
};