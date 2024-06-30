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

