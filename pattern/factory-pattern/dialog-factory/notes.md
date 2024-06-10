Factory Design Pattern  

<p> 

Example : 

You are required to construct a Dialog Class which is composed of a 
"Button" object and a render functionality. Now button can be of various 
types, Windows Button or Web Button etc. You don't want to create a switch 
case based design inside the Dialog class for handling this different kinds of 
user request. This also violates OCP for a new types of button coming in. 

A good approach is to make the Dialog Class compose a "generic" button and have 
a factory method "createButton" handle any dynamic button request. 

To sum it up, use a factory method design pattern to create different kinds of objects of a 
class without touching the original class. Different kinds of objects may have different interactibility 
which can be achieved through inheritance and abstraction. Make the class depend on the abstraction of button 
than the concrete button itself. 

</p> 