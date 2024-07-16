<p> 
Builder design pattern is a creational design pattern, it is used when the object creation is composed 
of several steps, that we find convenient to delegate the object creation to a Builder class. Also you 
can hide the getters and setters of the original class from the client by making it private and the builder
class a friend. In this way only Builder class has the authority to create and modify the objects. Additionally, 
your original class/object can provide an interface for the builder classes, that you just implement a builder
interface in a concretebuilder class. Runtime polymorphism takes care of delegating the method calls to the 
concretebuilder classes. Also you can hire a director to simply the steps for the builder class method calls. 
This does not stop here, if you feel that the builder class needs to be split into multiple subbuilders, you 
can do it by something like a facet pattern. See facet builder example for more. 

Use-Case: 

- say you are a aeroplane manufactoring company and manufactures different kinds of planes.
- 1st requirement is to separate out the aeroplane "build" construction process from the aeroplane class. 
you have other functionalities for a aeroplane like fly (), takeoff (), refuel () etc which you want to implement 
without having any coupling with the aeroplane build types like what engine it has, what kind of propeller it has etc. (OCP)
- Next requirement is you don't want the client to wrongly build up an aeroplane. It has various parts of build say 20. (Engine, Propeller ...) 
One way is "telescoping constructor" where the client calls (param1, param2, ...param20) but this is not nice. 
So you want to delegate the task of the building to a veteran builder class. 
- What you can do is have an interface of your aeroplane class build objects. Like buildengine (), buildpropeller(), 20 such. 
Any concrete builder who wants to build an aeroplane needs to implement this interface. 
- But now the question remains, who will call the abstract methods of the concrete builder is a right fashion, client can still mess up right? 
- To solve this have a director class to call all the methods in a correct order. 
- Thereby the client can just call the director class with the "desired" Concrete builder. Concrete builder will dispatch the 
build work at runtime to the correct builder through the builder interface and produce the aeroplane build. Once produce it returns the build product 
and discards the builder pointer to the plane object so that the client can longer modify the plane. 
- Facet and fluent builders are just easing out the calling process functionally they don't do much. 

</p>