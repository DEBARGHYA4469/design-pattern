<p> Builder design pattern is a creational design pattern, it is used when the object creation is composed 
of several steps, that we find convenient to delegate the object creation to a Builder class. Also you 
can hide the getters and setters of the original class from the client by making it private and the builder
class a friend. In this way only Builder class has the authority to create and modify the objects. Additionally, 
your original class/object can provide an interface for the builder classes, that you just implement a builder
interface in a concretebuilder class. Runtime polymorphism takes care of delegating the method calls to the 
concretebuilder classes. Also you can hire a director to simply the steps for the builder class method calls. 
</p>