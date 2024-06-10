#include "bits/stdc++.h"

class Point {
	private: 
		float x, y; 
		Point (float x, float y) : x (x), y (y) {} 
	private: 
		class PointFactory {
			public: // all function have to be static, else the private - public breaks. 
				static Point Cartesian (float x, float y) { return {x, y} ; }
				static Point Polar (float rho, float theta) { return { rho * cos (theta), rho * sin (theta) } ;}			
		};
	public: 
		/* expose PointFactory through Point for encapsulation and abstraction, user need not be bothered with an inner class details! */
		static PointFactory factory; // static object
		void print () const {
			std::cout << "x= " << x << " y=" << y << std::endl;
		} 
}; 