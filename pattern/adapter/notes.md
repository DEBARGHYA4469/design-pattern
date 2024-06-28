* Adapter pattern is a contruct to conform a interface X to a different interface Y and mostly providing support for X for a library which supports Y.

* Example : 

Interface : X 

```
class Ix {
	virtual void f1() = 0;
	virtual void f2() = 0;
	virtual void f3() = 0; 
}; 
```

Library : L 

```
struct L {
	Ix* x;
	L(x) : x(x) {}  
	void do () {
		x->f1(); 
		x->f2();
	}
}; 
```

Interface : Y 

```
class Iy {
	virtual void g1() = 0;
	virtual void g2() = 0;
	virtual void g3() = 0;
}; 
```

Now if you call L(y) you will get compile time error. 

* Solution : Create a adapter class for Y which implements Ix.

```
class AdapterY_to_X : public Ix{
	private: 
		Iy* y; 
	public: 
		AdapterY_to_X(Iy* y) : y(y) {}
		virtual void f1() override {
			y->g1(); 
			y->g2(); 
		}
		virtual void f2() override {
			y->g3();
		}
		virtual void f3() override {
			y->g1(); 
		}  
}; 	
```



