### Strategy Design Pattern 

- Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.

- Similar to `State` pattern but here the difference is the `Strategies` don't transform among each other. There is no finite state machines. In state design you can alter the context any time.  

- So you can use template programming and write `static` strategy pattern. 