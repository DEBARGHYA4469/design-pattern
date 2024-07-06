### Curiously Recurring Template Pattern (CRTP) 

- CRTP also known as "upside-down polymorphism". 
- General form : 

```cpp
template <typename T>
class Base {
	void interface (){ 
		static_cast<T*>(this)->impl();
	}
	static void foo () {
		T::bar();
	}
};

class Derived : Base <T> {
	void impl();
	static void bar();
}
```
- Polymorphic Chaining, not possible with Virtual functions

```cpp

template <typename T> 
class Base {
public:
	Base () {}
	T* foo1 () { return static_cast<T*>(this); }
	T* foo2 () { return static_cast<T*>(this); }
};

class Derived : Base<Derived> {
	Derived* foo3 () { return this; }
};

void main (){
	Derived* d = new Derived ();
	d->foo1()->foo3()->foo2();
}
```

- One disadvantage is you cannot have a abstract class which can point to any Base object. For that maintain a separate `AbstractBase` and let Derived inherit from `AbstractBase`. 


## Multi-Methods
