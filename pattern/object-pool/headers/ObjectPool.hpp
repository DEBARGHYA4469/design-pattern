#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class DatabaseConnection {
public:
	DatabaseConnection () {
		cout << "DatabaseConnection created" << endl;
	} 
	~DatabaseConnection () {
		cout << "DatabaseConnection destroyed" << endl;
	}
	void connect () {
		cout << "connecting to db..." << endl;
	}
	void disconnect () {
		cout << "disconnecting from db ..." << endl;
	}  
};

class ConnectionPool {
private: 
	typedef shared_ptr<DatabaseConnection> dbptr;
	size_t poolsize = 0;
	std::vector<dbptr> availableconnections;
	mutex m;
public:
	ConnectionPool (size_t poolsize) : poolsize (poolsize) {
		for (size_t i=0;i<poolsize;i++) 
			availableconnections.push_back(make_shared<DatabaseConnection>());
	}
	dbptr acquire () {
		unique_lock<mutex> lock(m);
		if (availableconnections.empty()) { return nullptr; }
		auto conn = availableconnections.back();
		availableconnections.pop_back();
		return conn;
	}

	void release (dbptr conn) {
		unique_lock<mutex> lock(m);
		availableconnections.push_back (conn); 
	}  
};

 