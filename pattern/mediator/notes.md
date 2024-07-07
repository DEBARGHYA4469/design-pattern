## Mediator Pattern 

- Components of a game go in an out all the time. 
- Without a mediator if you want the components to communicate among each other, the components have to store each other information, which is not optimal. 
- Hence, a `mediator` pattern is maintained, which stores info about all the objects in the pool and any request from any object to any other object is made through that pool. 
- Helps reduce chaotic dependencies between objects.


### Event Broker: 

- form of a event driven architecture where the producer and consumer communicate through a intermediate `broker` entity. 
- boost/signals2 library is not compatible with gnu++20.
- signals2 library is used for managing callback functions also known as slots and signals. 
- It's a type safe, thread safe, flexible implementation, used in GUI programming, event driven systems, asynchronous programming. 
- Decouples producer from consumer.
- `boost::signals2::signal <ret-type (args ...)> events`. events.connect adds a callback function onto events queue. 
- As you do, events (args...), it will invoke the callback fcns. 

Consider a simple Game of football: 

- There are `players` : objects in the game.
- Players interact among each other : `player:a` can tackle `player:b`.
- Interactions are handled through a `Mediator` class, in this case, `Game` Class. 
- There can be watchers or broadcasters like TV, Referee, Coach. There are `Observers`.
- We create an instance of these observers and that adds a callback function to the `Game: events` slot using `events.connect`. 
- Whenever we receive a `signal`/`event` with `events(...)`, all the slots/call back functions in the events are called.  
