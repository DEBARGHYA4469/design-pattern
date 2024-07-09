#include "Observer.hpp"

/* CRTP */
struct Person : Observable<Person>
{
	string name;
	int age;
	int height;

	Person (string name, int age, int height) : name (name), age (age), height (height) {}

	void set_age (int age) {
		if (age == this->age) return;
		this -> age = age; 
		this -> notify (this, "age"); 
	}

	void set_height (int height) {
		if (this->height == height) return;
		this -> height = height;
		this -> notify (this, "height");
	}
};

struct HeightTracker : Observer <Person> {
	virtual void listen(Person* source, string changed) override {
		if (changed == "height") {
			cout << source -> name << " got a new height, " << source -> height << endl;
 		}
	}
};

struct AgeTracker : Observer <Person> {
	virtual void listen(Person* source, string changed) override {
		if (changed == "age") {
			cout << source -> name << " got older, his new age " << source -> age << endl;
 		}
	}
};