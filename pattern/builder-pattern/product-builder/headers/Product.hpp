#pragma once
#include "bits/stdc++.h"

class Product {
	public: 
		std::string product_name; 
		std::vector<std::string> parts;
	public:
		~Product () { } 
		void show () {
			std::cout << "Showing the parts for " << product_name << std::endl;
			for (auto &p : parts) {
				std::cout << p << ", "; 
			}
			std::cout << std::endl << std::endl;
		} 
}; 