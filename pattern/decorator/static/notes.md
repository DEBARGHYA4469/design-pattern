### Decorator Pattern 

Mixin Interface 
Perfect forewarding https://iamsorush.com/posts/perfect-forwarding-cpp/, https://en.cppreference.com/w/cpp/utility/forward

One issue with static decorator pattern was that it could not call the specific methods for a call from its decorator. Example from ColoredShape (blueCircle) objects you cannot Circle::resize method as ColoredShape is generic.

To solve this we will use mixin inheritance and perfect forewarding. 

```cpp
template <typename T>
class ColoredShape : public T {
	static_assert (std::is_base_of<Shape, T>::value, "Template must be a shape type"); 
	/* use concepts in c++=20*/
public:
	std::string color; 
	ColoredShape () = default;

	// mixin inheritance 
	template <typename ...Args>
	ColoredShape (const std::string color, Args ...args) : T (std::foreward<Args>(args)...), color (color) { } 
} 

template <typename T>
class TransparentShape : public T {
	static_assert (std::is_base_of<Shape, T>::value, "Template must be a shape type"); 
	/* use concepts in c++=20*/
public:
	std::string transparency; 
	TransparentShape () = default;

	// mixin inheritance 
	template <typename ...Args>
	TransparentShape (const std::string transparency, Args ...args) : T (std::foreward<Args>(args)...), transparency (transparency) { } 
} 

ColoredShape<Circle> blueCircle ("blue", 2);
TransparentShape<ColoredShape<Circle>> tbc ("0.9", "blue", 2); 
tbc.transparency; 
``` 

You can have something like this with a static decorator pattern 

```cpp
Colored<
	Resizeable<
		Transparent<
			Drawable<
				Shape>>>> bluecircle ("blue", 0.5, 0.8, ..., 3.5);
```

note you can mark virtual functions in the decorator classes using Mixin's if the after the template expansions it is going to ask for the base classes. 

i.e 

```cpp
template <typename T>
class Derived : T {
	virtual foo () const override {} 
}; 
```

This is ok. Compiler not going to generate anything. 

```cpp
class Base {
	virtual void foo() = 0;
};

template <typename T>
class Derived : T {
	virtual void foo () const override {} 
}; 

Derived<Base> obj;
```

This is ok, because compiler going to generate Derived : Base. 
But you cannot mark say bar() as virtual if Base does not override and we are going to generate it. 

Basic idea of static decorator instead of writing out the multi level inheritance explicitly you use template and mixins to generate them implicitly and generate whatever is required. 
