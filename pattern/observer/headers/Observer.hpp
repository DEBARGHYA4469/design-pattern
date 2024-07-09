#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

template <typename T> 
struct Observer{
	virtual void listen(T* source, string changed) = 0;
};

template <typename T> 
struct Observable{
 	vector<Observer<T>*> observers;
 	typedef std::recursive_mutex mutex_t;
 	mutex_t mtx;

 	void notify (T* source, string changes) {
 		std::scoped_lock<mutex_t> lock(mtx); 
 		for (auto observer: observers) {
 			if (observer != nullptr) observer->listen(source, changes);
 		}
 	}
 	void subscribe (Observer<T>* observer) {
 		scoped_lock<mutex_t> lock(mtx); 
 		observers.emplace_back(observer);
 	}
 	void unsubscribe (Observer<T>* observer) {
 		observers.erase (remove (observers.begin(), observers.end(), observer), observers.end());					
 	}
};