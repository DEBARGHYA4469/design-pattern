### Iterator Design Pattern 

- Iterator design pattern is used to traverse a aggregate/container object like stack, list, array
- Isolate the traverse logic from the original Aggregate class. 
- Defines a generic Iterator interface, which gives consistency in using iterators. 
- Also iterator interface is defined on a abstract Aggregate interface, 'Iterable'. 
- Each concrete aggregate implements this 'Iterable' interface to be used with Iterators. 

```cpp

// Iterator Interface
template <typename T>
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

// Concrete Iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T> collection;
    size_t position = 0;
public:
    ConcreteIterator(const std::vector<T>& coll) : collection(coll) {}

    bool hasNext() override {
        return position < collection.size();
    }

    T next() override {
        return collection[position++];
    }
};

// Aggregate Interface
template <typename T>
class Aggregate {
public:
    virtual Iterator<T>* createIterator() = 0;
};

// Concrete Aggregate
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> elements;
public:
    void add(const T& element) {
        elements.push_back(element);
    }

    Iterator<T>* createIterator() override {
        return new ConcreteIterator<T>(elements);
    }
};

// Client Code
int main() {
    ConcreteAggregate<int> aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);

    Iterator<int>* iterator = aggregate.createIterator();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    delete iterator; // Clean up
    return 0;
}
```

https://www.fluentcpp.com/2018/04/27/tag-dispatching/
