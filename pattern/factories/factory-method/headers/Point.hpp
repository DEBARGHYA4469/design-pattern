#include "bits/stdc++.h"

class Point {
	private: 
		float x, y; 
		Point (float x, float y) : x(x), y(y) {} 
	public:	
		void print () const {
			std::cout << "x=" << x << " y=" << y << std::endl; 
		} 
		static Point Cartesian (float x, float y) {
			return { x, y }; 
		}
		static Point Polar (float rho, float theta) {
			return { rho * cos (theta), rho * sin (theta) }; 
		}
}; 