### Observer Design Pattern : 


##### The Observer design pattern is a behavioral design pattern used to establish a one-to-many relationship between objects. This allows one object (the subject) to notify multiple dependent objects (observers) about changes in its state, without requiring the subject to know anything about the observers.

* Key Components

- Subject: The object that maintains a list of its dependents (observers) and notifies them of any state changes.
- Observer: The objects that need to be notified of changes in the subject. Each observer registers with the subject to receive updates.
- ConcreteSubject: A concrete implementation of the Subject interface or abstract class.
- ConcreteObserver: A concrete implementation of the Observer interface or abstract class, which updates its state based on notifications from the subject.

* How It Works

- Attach: Observers register themselves with the subject to receive updates.
- Detach: Observers can unregister themselves if they no longer wish to receive updates.
- Notify: When the subject's state changes, it sends a notification to all registered observers.

* Observer Pattern using CRTP

```cpp
template <typename T> 
struct Observer{
	virtual void listen(T* source, string changed) = 0;
};

template <typename T> 
struct Observable{
 	vector<Observer<T>*> observers;
 	typedef std::recursive_mutex mutex_t;
 	mutex_t mtx;

 	void notify (T* source, string changes) {
 		std::scoped_lock<mutex_t> lock(mtx); 
 		for (auto observer: observers) {
 			if (observer != nullptr) observer->listen(source, changes);
 		}
 	}
 	void subscribe (Observer<T>* observer) {
 		scoped_lock<mutex_t> lock(mtx); 
 		observers.emplace_back(observer);
 	}
 	void unsubscribe (Observer<T>* observer) {
 		observers.erase (remove (observers.begin(), observers.end(), observer), observers.end());					
 	}
};
```

https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom