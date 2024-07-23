#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct GameAI
{
public:
	void turn () {
		collectresources(); 
		buildStructures();
		buildUnits();
		attack();
	}

protected:

	std::vector<string> A;

	void collectresources () {
		for (auto& s: A) collect(s);
	}

	// Some steps defined as abstract (pure virtual methods)
	virtual void buildStructures() = 0;
	virtual void buildUnits() = 0;

    // Additional template method
   void attack() {
        std::string enemy = closestEnemy();
        if (enemy.empty()) {
            sendScouts("center of the map");
        } else {
            sendWarriors(enemy);
        }
    }

    // Abstract methods for attack operations
	virtual void sendScouts(const std::string &position) = 0;
	virtual void sendWarriors(const std::string &position) = 0;

private:
	void collect (string& s) {
		cout << "collecting resources from " << s << endl;
	}
	string closestEnemy(){
		return "enemyPosition";
	}
};

struct OrcsAI : GameAI {
	virtual void buildStructures(){
		std::cout << "Orcs building structures" << std::endl;
	}
	virtual void buildUnits(){
    	std::cout << "Orcs building units" << std::endl;
    }
	virtual void sendScouts(const std::string &position){
    	std::cout << "Orcs sending scouts to " << position << std::endl;
    }
	virtual void sendWarriors(const std::string &position){
    	std::cout << "Orcs sending scouts to " << position << std::endl;
    }
};

struct MonstersAI : GameAI {
	virtual void buildStructures(){
		std::cout << "Monsters building structures" << std::endl;
	}
	virtual void buildUnits(){
    	std::cout << "Monsters building units" << std::endl;
    }
virtual void sendScouts(const std::string &position){
    	std::cout << "Monsters sending scouts to " << position << std::endl;
    }
virtual void sendWarriors(const std::string &position){
    	std::cout << "Monsters sending scouts to " << position << std::endl;
    }
};