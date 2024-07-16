## Mediator Pattern 


### When to use? 

- when you have component or classes which you cannot reuse and keep making different version of it. 
- Component A is dependent on Component B,C,D in one place, C,D in other or X,Y in some place. 
- All of A,B,C,... share some common interface. 
- Basically if A can be composed of multiple components of same interface. 
- How A is going to communicate with any of its related component. 
- Let mediator do it. 

Game Example:

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


### UI Component

- If there are multiple related UI component, they are interact with another, design a mediator for them to talk to another. 

```cpp
#include <iostream>
#include <string>
#include <memory>

// Forward declaration of Component class
class Component;

// Mediator interface
class Mediator {
public:
    virtual void notify(Component* sender, const std::string& event) = 0;
};

// Component class
class Component {
protected:
    Mediator* dialog;
public:
    Component(Mediator* dialog) : dialog(dialog) {}

    virtual void click() {
        dialog->notify(this, "click");
    }

    virtual void keypress() {
        dialog->notify(this, "keypress");
    }
};

// Concrete components
class Button : public Component {
public:
    using Component::Component;
    // Additional Button-specific functionality
};

class Textbox : public Component {
public:
    using Component::Component;
    // Additional Textbox-specific functionality
};

class Checkbox : public Component {
public:
    using Component::Component;

    void check() {
        dialog->notify(this, "check");
    }
    // Additional Checkbox-specific functionality
};

// Concrete mediator class
class AuthenticationDialog : public Mediator {
private:
    std::string title;
    std::unique_ptr<Checkbox> loginOrRegisterChkBx;
    std::unique_ptr<Textbox> loginUsername, loginPassword;
    std::unique_ptr<Textbox> registrationUsername, registrationPassword, registrationEmail;
    std::unique_ptr<Button> okBtn, cancelBtn;

public:
    AuthenticationDialog() {
        // Create all component objects and establish links
        loginOrRegisterChkBx = std::make_unique<Checkbox>(this);
        loginUsername = std::make_unique<Textbox>(this);
        loginPassword = std::make_unique<Textbox>(this);
        registrationUsername = std::make_unique<Textbox>(this);
        registrationPassword = std::make_unique<Textbox>(this);
        registrationEmail = std::make_unique<Textbox>(this);
        okBtn = std::make_unique<Button>(this);
        cancelBtn = std::make_unique<Button>(this);
    }

    void notify(Component* sender, const std::string& event) override {
        if (sender == loginOrRegisterChkBx.get() && event == "check") {
            if (loginOrRegisterChkBx->checked) {
                title = "Log in";
                // 1. Show login form components.
                // 2. Hide registration form components.
            } else {
                title = "Register";
                // 1. Show registration form components.
                // 2. Hide login form components.
            }
        }

        if (sender == okBtn.get() && event == "click") {
            if (loginOrRegisterChkBx->checked) {
                // Try to find a user using login credentials.
                // if (!found)
                // Show an error message above the login field.
            } else {
                // 1. Create a user account using data from the registration fields.
                // 2. Log that user in.
                // ...
            }
        }
    }
};

int main() {
    AuthenticationDialog dialog;
    // Example usage
    dialog.notify(dialog.loginOrRegisterChkBx.get(), "check");
    dialog.notify(dialog.okBtn.get(), "click");
    return 0;
}

```