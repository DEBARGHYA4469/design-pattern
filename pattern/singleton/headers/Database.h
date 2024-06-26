#pragma once
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <boost/lexical_cast.hpp>

using namespace boost;

/* Interface */
class Database {
public:
	virtual int get_population (const std::string& name) = 0; 
}; 

class SingletonDatabase: public Database {
	
	std::map<std::string, int> capitals; 

	SingletonDatabase () {
		std::cout << "Initializing Database ..." << std::endl;
		std::ifstream ifs("capitals.txt");
		if (ifs.fail()) {
		    std::cerr << "Failed to open the file." << std::endl;
		}
		std::string city, population;
		while (std::getline(ifs, city)) { 
			std::getline (ifs, population);
			int pop = lexical_cast<int>(population);
			capitals[city] = pop;
		}
	}
public:
	SingletonDatabase (SingletonDatabase const&) = delete;
	void operator= (SingletonDatabase const&) = delete;
	static SingletonDatabase& get () {
		static SingletonDatabase db; 
		return db; 
	}
	int get_population (const std::string& name) override {
		return capitals[name];
	}
};

class DummyDatabase : public Database {
	std::map<std::string, int> capitals;
	public:
		DummyDatabase () {
			capitals["city1"] = 10;
			capitals["city2"] = 20;
			capitals["city3"] = 30; 
		}
		int get_population (const std::string& name) override {
			return capitals[name];
		}  
};

struct SingletonRecordFinder {
	int total_population (std::vector<std::string>& cities) {
		int result = 0;
		for (auto& city: cities){
			result += SingletonDatabase::get().get_population(city);
		}
		return result;
	}
};

/* Use dependency injection in code for better testablity */
struct ConfigurableRecordFinder {
	Database& db;
	ConfigurableRecordFinder (Database& db) : db(db) {}
	int total_population (std::vector<std::string>& cities) {
		int result = 0;
		for (auto& city: cities){
			result += db.get_population(city);
		}
		return result;
	}
}; 

/* Integration Test */ 
TEST (SingletonRecordFinderTest, TotalPopulation) {
	SingletonRecordFinder rf; 
	std::vector<std::string> v {"delhi", "osaka"};
	EXPECT_EQ(rf.total_population(v), 700);
}

/* Unit Test */
TEST (ConfigurableRecordFinderTest, TotalPopulation) {
	DummyDatabase db;
	ConfigurableRecordFinder rf(db); 
	std::vector<std::string> v {"city1", "city2"};
	ASSERT_EQ(rf.total_population(v), 30);
}