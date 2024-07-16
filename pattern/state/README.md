### State Design Pattern 

- Aka Finite State Machine 
- Create an interface for `States`. 
- Have all the `States` implement the abstract `State`. Also have a virtual function for changing the `States`
- So all the `if else` for any `State` related functions like ```foo() { if state1 : do this, if state 2: do this; }``` can now be delegated to the dynamic dispatch via the State interface and concrete State objects.

https://stackoverflow.com/questions/445127/passing-this-to-a-function-from-within-a-constructor#:~:text=So%20it%20is%20perfectly%20valid,them%20in%20your%20constructor%20code.
