### Dynamic Decorator 

Say you have class Shape and now you want various kinds of Shape like Circle, Square. This can be achieved by inheritance. 

Later at some point you want ColoredShapes like BlueCircle, RedSquare etc. One way is to compose Shape class with a color param. Later you may need transparent Shapes. 
Slowly you will end up violating SRP / OCP if you are constantly changing Shape class for a any new requirement.

One solution is to use a decorator class. 

```cpp
class Shape {
	virtual void draw () = 0; 
};

class Circle : public Shape {...};
class Square : public Shape {...};

class ColoredShapes : public Shape {
	Shape* shape;
	std::string color; 
	...
} 
```

This is called dynamic decorator. One downside is you cannot call Circle specific methods from ColoredShapes. It can only call methods from Shape interface.

https://stackoverflow.com/questions/9192077/is-inline-implicit-in-c-member-functions-defined-in-class-definition

