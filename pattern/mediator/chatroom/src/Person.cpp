#include "Person.hpp"
#include "ChatRoom.hpp"

void Person::private_message (std::string contact, std::string msg) const {
	room->message(this->name, contact, msg); 
}
void Person::say (std::string msg) const {
	room->broadcast (this->name, msg);
}
void Person::receive (std::string origin, std::string msg){
	std::cout << "[" << this->name << "'s chat session] " 
			  << origin << " says : " << msg << std::endl;
	this->mymessages.emplace_back(origin + ":" + msg); 
}