#pragma once
#include "Multiton.hpp"

enum class Importance {
	primary, 
	secondary,
	tertiary
}; 

class Printer {
public: 
	Printer () {
		++total_instance_count; 
		std::cout << "A total of " << Printer::total_instance_count << " Printer is created." << std::endl;
	}
	static int get_count () {
		return Printer::total_instance_count;
	}  
private: 
	static int total_instance_count;
}; 

int Printer::total_instance_count = 0;