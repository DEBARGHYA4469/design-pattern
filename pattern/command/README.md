### Command Design Pattern 

As the name suggest, command design pattern is about encapsulating the command used to alter the state of the object. Don't call the setters and mutators directly. Instead have a separate Command Interface, let concrete command implement this interface. In this way you can decouple the command executation from the original receiver class and also support command history, undo operation, adding new commands w/o changing the orignal class. 

```
Original "Receiver Class" : << RemoteControllable >> 

RemoteControl "Invoker" <----- RemoteControllable* 

Invoker -> [btn1, btn2, btn3 ...] 

Link btn1 --> ConcreteCommand ... 

Create concreteCommands [cmd1, cmd2, cmd3, ...]. 
```


- In simple command design pattern, idea is to have a invoker (remote), and bind commands to the invoker interface. These are concrete commands. 

- Use the command design when you want to separate the queries and command and want to support queuing, history of command, undo operations etc. Basically a encapsulation layer on top of the commands for a class. Also to protect any class from changes when its command changes, used to decouple the command class from its invoker or receiver class. 

- In the example of `cut-copy-paste`, we decoupled the command from its application class receiver as well as from the Button class. So the button developers can develop independently as well as the application developers. We can bind the command methods separately.
