Pimpl Idiom (Pointer to Implementation) in C++ 

- It is used to hide the implementation details of a class from its interface (header files) 
- Helps reduce compilation dependencies. Changes in implementation does not require the client of the interface to recompile. 
- Stable ABI since the client interface does not change frequently. 

Example: 

Suppose you are coding a gyroscope class which 

- Bad design : 

```hpp
// public interfaces
// MyClass.h

#include "SecretEncryption.h" // BAD: May not be exposed to the user! 
class MyClass {
private: 
	int data;
	int username;
	int password;
	Encryption* encryption; /* BAD: User does not need to know about this!*/  
public:
	MyClass () = default;
	/* OK : below two methods are client facing, it is alright to have them*/ 
	void change_password () const;
	void validate_user () const;

	/* USER need not know */
	void set_encryption_param (int, int, int);
	void set_rsa_private_key (int, int, int); 
	/* Tomorrow if the encryption type changes and we use ecdsa any client dependent on this should recompile, ABI unstable! */
};  
```


- Good Design 

```cpp 
// public interfaces
// MyClass.h
// Ship this to client ... 
class MyClass {
private: 
	int data;
	int username;
	int password;
	class Impl; // foreward declaration. 
	std::unique_ptr <Impl> pImpl;
public:
	MyClass ();
	~MyClass(); 
	/* OK : below two methods are client facing, it is alright to have them*/ 
	void change_password () const;
	void validate_user () const;

};  

// MyClassImpl.cpp 
#include "MyClass.h"
#include "SecretEncryption.h"

class MyClass::Impl {
public: 
	void set_encryption_param (int, int, int) {

	} 
	void set_rsa_private_key (int, int, int) {

	}
	void validate_user () {

	}  
}; 

MyClass::MyClass() {}
MyClass::~MyClass() {} 

void change_password () const {
	pImpl->set_encryption_param(); 
	... 
}
void validate_user () const { 
	pImpl->validate_user();  
}  
```


#### Shrink-Wrapped pImpl (Herb Shutter's Compilation Firewalls)
https://herbsutter.com/gotw/_101/
https://herbsutter.com/gotw/_100/


```
/*				widget 							            widget::impl 

								|
								|			... hidden members 			
	... non hidden members 					|
	pimpl  -----------------------------> 			|
 							compilation firewall 

*/

```

