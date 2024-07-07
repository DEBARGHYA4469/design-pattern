#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

struct ChatRoom;

// Person class 
struct Person
{
	std::string name;
	std::vector<std::string> mymessages;
	ChatRoom* room; // Mediator
	// ctor 
	Person (std::string name): name(name) {}
	void private_message (std::string contact, std::string msg) const;
	void say (std::string msg) const;
	void receive (std::string origin, std::string msg);
};
