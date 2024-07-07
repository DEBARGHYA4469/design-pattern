#include "ChatRoom.hpp"
#include "Person.hpp"


void ChatRoom::broadcast (std::string origin, std::string msg){
	for (Person* p: people){
		if (p->name != origin){
			p->receive (origin, msg); 
		}
	}
} 

void ChatRoom::message (std::string origin, std::string dest, std::string msg){
	for (Person* p: people)
		if (p->name == dest)
			p->receive (origin, msg); 
} 
void ChatRoom::join (Person* p){
	people.emplace_back (p);
	p->room = this;
	std::string msg = p->name +  " joins the chat!";
	this->broadcast ("room", msg);
}