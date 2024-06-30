#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Logging decorator for any function */
template <typename Func>
auto timing_decorator(Func func) {
	/* return a decorated lambda*/
	/* capture func (function pointer) by value */
	return [func](auto&& ...args){
		auto start = std::chrono::high_resolution_clock::now();
		((std::cout << args << ","), ...) << std::endl; // Fold expression
		auto result = func (std::forward<decltype(args)>(args)...);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		 std::cout << "Function executed in: " << duration.count() << " seconds" << std::endl;
		return result; 
	}; 
}