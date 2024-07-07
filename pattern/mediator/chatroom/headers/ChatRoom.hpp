#pragma once 
#include "Person.hpp"
#include "bits/stdc++.h"
#include "gtest/gtest.h"

struct ChatRoom {
	std::vector<Person*> people;

	void broadcast (std::string origin, std::string msg); 
	void message (std::string origin, std::string dest, std::string msg); 
	void join (Person* p);  
}; 