### Chain of Responsibility 

- The Chain of Responsibility is a behavioral design pattern that allows an object to pass a request along a chain of potential handlers until the request is handled. Each handler in the chain either processes the request or passes it to the next handler in the chain. This pattern decouples the sender of a request from its receiver by giving more than one object a chance to handle the request.

Here’s a breakdown of the Chain of Responsibility pattern:

1. Handler Interface: This defines an interface for handling requests. It typically has a method to process a request and a reference to the next handler in the chain.

2. Concrete Handlers: These are the classes that implement the handler interface. Each concrete handler decides either to process the request or to pass it to the next handler.

3. Client: The client creates and assembles the chain of handlers and then sends requests to the chain.