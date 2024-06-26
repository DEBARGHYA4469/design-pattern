#pragma once
#include "bits/stdc++.h"
#include <gtest/gtest.h>

template <typename T, typename KeyT = std::string>
class Multiton {
private:
	static std::map <KeyT, std::shared_ptr<T>> instances;
public:
	static std::shared_ptr<T> get (const KeyT& key){
		const auto it = instances.find (key);
		if (it != instances.end()) return it->second; 
		auto instance = std::make_shared<T>();
		instances[key] = instance;
		return instance;
	} 
protected: 
	Multiton () = default; 
	virtual ~Multiton () = default;   
};  

template <typename T, typename KeyT>
std::map<KeyT, std::shared_ptr<T>> Multiton<T, KeyT>::instances;