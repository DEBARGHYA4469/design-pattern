### Visitor Pattern 

- Say you have to class `Expression` and you want various other Inspector classes which wants to go through the expression tree. 
- Tne inspector classes or visitor classes would go through expression tree but we want to keep the expression tree closed OCP. 
- Now Expression class has multiple kinds of object and based on the runtime object state you want to call the specific visitor method. 
- Like `expr_obj -> some_speacial_visitor ()`. This can only be achieved if some_speacial_visitor is in same class expr_obj and in the interface. run time polymorphism. But we told, we cannot do this. 
- Double dispatch : 
- Let Expression class implement a generic `accept (Visitor* v) : v -> visit(this);` function which accepts a particular visitor and during runtime bind it to the correct visitor method. Let the Visitor class define various flavours of the visit function.  
- Checkout the example for cyclic visitor, you can write as many visitor as you want w/o changing Shape class. OCP is kept. 


Issue with the above design:  

- Also every visitor now has to implement all of visitor virtual method. 
- You cannot create a visitor only for say circle class after circle class is `closed`.


#### Acyclic Visitor via RTTI (Run Time Type Information)


* Say you have to a collection of abstract objects `<O>` of same type `T`. 
* `<O> = {O1, O2, O3, O4, O5, ..., O10}`, O[i]'s are determined at runtime.
* How do you create a visitor for `<O>`? 
* Use a BaseVisitor class for T.
* Implement `BaseVisitor` as a `concreteVisitor`. But this concretevisitor has to implement some visits specific to some types t1, t2, t3...
* BaseVisitor does not have any virtual func for t1, t2, t3. 
* Create a toplevel Visitor interface templated with <Types>. Like `Visitor<T1>, Visitor<T2>` etc.
* Inherit `Visitor<T1>, Visitor<T2>` into `concreteVisitor`. 
* Inside the Type classes T1, slice `BaseVisitor (ConcreteVisitor:Visitor<T1>, Visitor<T2> ...)` --> `Visitor<T1>`. 