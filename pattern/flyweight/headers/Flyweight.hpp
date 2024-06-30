#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

/* Car Model */
struct CarModel{
	string brand_, model_, color_;
	CarModel () = default;
	~CarModel () = default;
	CarModel (string brand_, string model_, string color_) : 
		brand_ (brand_), model_ (model_), color_ (color_) {
		cout << "New car created: " << brand_ << "_" << model_ << "_" << color_ << endl; 
	} 
};

/* Flyweight // Common structure */
struct Flyweight {
	map <string, CarModel*> flyweight;
	string getKey (const CarModel& c) const {
		return c.brand_ + "_" + c.model_ + "_" + c.color_;
	}
	Flyweight () = default;
	~Flyweight () {}
	Flyweight (std::initializer_list<CarModel> carList) {
		for (const CarModel &c: carList) {
			string key = getKey (c);
			flyweight[key] = new CarModel(c);
		}
	}
	void show_cars () const {
		cout << "\nListing all cars in the flyweights: " << endl;
		for (auto a = flyweight.begin(); a!=flyweight.end(); a++) {
			cout << a->first << endl;
		}
		cout << endl;
	}
	CarModel* checkout (const CarModel& c) {
		string key = getKey (c);
		if (flyweight.find(key) == flyweight.end()) flyweight[key] = new CarModel(c);
		return flyweight[key];
	} 
};


struct Police {
	string name; 
	CarModel *c;
	Police () = default;
	Police (Flyweight& ff, string name, string CarBrand, string CarModel, string CarColor) {
		this->name = name;
		c = ff.checkout ({CarBrand, CarModel, CarColor});
	} 
}; 

void AddPoliceToDatabase ();











