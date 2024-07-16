### Template-Method Design Pattern 


#### what is Template Method design pattenr?

- The Template Method design pattern is a behavioral design pattern that defines the skeleton of an algorithm in a base class but allows subclasses to override specific steps of the algorithm without changing its structure. This pattern is particularly useful when you have an algorithm with invariant parts that can be reused across different contexts, while allowing customization of certain steps by subclasses.

#### Key Concepts

- Template Method: This is the method in the base class that defines the structure of the algorithm. It consists of calls to other methods, some of which may be abstract or have default implementations that can be overridden by subclasses.

- Abstract Methods: These are methods declared in the base class without implementations. Subclasses must provide concrete implementations for these methods.

- Hook Methods: These are methods with default implementations in the base class. Subclasses can override these methods if they want to provide specific behavior, but it's not mandatory.

#### Structure

- Abstract Class: Contains the template method and abstract methods or hooks.
- Concrete Class: Inherits from the abstract class and provides specific implementations for the abstract methods or overrides the hook methods.