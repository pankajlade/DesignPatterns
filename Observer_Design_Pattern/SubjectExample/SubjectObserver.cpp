#include "SubjectObserver.hpp"

/**
 * The ConcreteSubject class is a subclass of Subject that provides concrete implementations of getState() and setState(). 
 * When the state changes using setState(), it calls the notify() method to notify all attached observers.
*/

// Concrete Subject class
class ConcreteSubject : public Subject {
public:
    int getState() override {
        return state;
    }

    void setState(int newState) override {
        state = newState;
        notify(); // Notify observers when the state changes
    }

private:
    int state = 0;
};

/**
 * The ConcreteObserver class is a subclass of Observer that implements the update() method. 
 * It registers itself with a subject in its constructor and detaches itself in its destructor. 
 * When the update() method is called, it retrieves the new state from the subject and performs the desired actions 
 * (in this case, printing the state to the console).
*/

// Concrete Observer class
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(Subject* subject) : subject(subject) {
        subject->attach(this);
    }

    ~ConcreteObserver() {
        subject->detach(this);
    }

    void update() override {
        int newState = subject->getState();
        std::cout << "Observer: Received new state: " << newState << std::endl;
    }

private:
    Subject* subject;
};


/**
 * In the main() function, we create a ConcreteSubject object, two ConcreteObserver objects that are attached to the subject, 
 * and then change the subject's state. As a result, the observers are automatically notified and update their state accordingly.
*/


int main() {
    // Create a subject and some observers
    Subject* subject = new ConcreteSubject();
    Observer* observer1 = new ConcreteObserver(subject);
    Observer* observer2 = new ConcreteObserver(subject);

    // Change the subject's state
    subject->setState(42);

    // Clean up
    delete observer1;
    delete observer2;
    delete subject;

    return 0;
}


/**
 * Remember to properly manage memory by deleting the dynamically allocated objects to prevent memory leaks.
 * Overall, the Observer pattern allows for loose coupling between subjects and observers, enabling.
*/