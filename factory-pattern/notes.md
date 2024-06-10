Factory Design Pattern 

<p> 

- Builder pattern helps build objects piece wise which have long list of parts 
to build and avoid telescoping constructors. But consider the following use-case 
Say you have a class "Point" which atleast does not have a many parts (x and y coordinate) 
but can have different ways of calling. You want the Point class to be as generic as possible 
so that it supports many ways of calling like Polar Coordinates, Cylindrical Coordinates etc.

- Specifically you want to achieve something like : 
	a. Point (rho = 2, theta = PI/4) 
	b. Point (x = 2, y = 2) 
	c. Point (r = 2, phi = 2) 

You see that this cannot be achieved in C++. You need something like an optional parameter 
to specify the type of Point. say : Point (float, float, enum PointType). Now the issue with
this approach is that it violates OCP. Any new coordinate system and we have to change Point Class. 
Also the switch case grows big inside the Point class. 

```cpp
switch
Case PointType::Cartesian -> x,y = ... 
Case PointType::Polar -> x,y = ... 
... 
```
Problem with this approach is that now the constructor needs to be called as Point (int x, int y, PointType type) 
which does not provide any information about x and y and what they're supposed to mean. This can lead to lot of 
confusion and a need to maintain a lengthy documentation. So we want to avoid this and separate out the object creation 
process to a "Factory class/method".

First we will look at Factory method (let the construction happen via methods with suitable names): 

- In factory method, we can make the constructor of the class private in that way the client 
cannot call the constructors directly. 
- We can place some static methods of different kinds of objects inside the public 
sections of the class which will return a Point object based on the call. 
- Disadvantage of this is that this again violates OCP. 

Next, approach is a concrete factory class. 

```cpp

class Point {
	float x, y;
	public: 
		Point (int x, int y) : x(x), y(y) {} 
};

class PointFactory {
	static Point Cartesian (float x, float y) {
		reutrn { x, y }; 
	} 
	static Point Polar (float rho, float theta) {
		return { rho * cos (theta), rho * sin (theta) }; 
	}
};

int main (){
	auto p = PointFactory::Cartesian (2, 3);
	auto q = PointFactory::Polar (2, PI/2);	
} 

```

This works but the issue is the discoverablity issue. Since Point has no information on PointFactory it may be hard for 
someone to discover the range of options provided by PointFactory. 

To solve this, we can emply an inner factory class, which is tied to the PointClass and is easily discoverable. Also, make 
point constructor private so that only inner factory can be called. 

</p>