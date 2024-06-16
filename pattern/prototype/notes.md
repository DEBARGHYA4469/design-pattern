<p> 

<h3> Prototype Pattern </h3>

If you have a object with large number of pointer member variables and want to support the 
clone functionality, meaning given a object you should be able to clone the object and change
few other fields. One straightforeward approach is to write a copy constructor which 
does deep copy, but you have to careful to deep copy every pointer.

Also you have to keep many constant prototype and manage them manually. 
Instead you can create a prototype factory, which will store many prototypes and expose 
the setters for only changeable fields. You can also mark all the fields of the initial class 
as private and only let the "friend prototype factory" create custom objects of that class based on some 
prototypes. You still have to deep copy the pointer types of the prototype layer. 

Also to avoid deep copy of multiple pointer member variables, use something like a serialiser and 
deserialiser and write a clone method for the class. 

</p>