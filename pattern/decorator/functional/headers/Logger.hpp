#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"

/* Logging decorator for any function */
template <typename Func>
auto logging_decorator(Func func) {
	/* return a decorated lambda*/
	/* capture func (function pointer) by value */
	return [func](auto&& ...args){
		((std::cout << args << ","), ...) << std::endl; // Fold expression
		auto result = func (std::forward<decltype(args)>(args)...);
		std::cout << "Function returned: " << result << std::endl;
		return result; 
	}; 
}