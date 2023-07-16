
/**
 * The Observer pattern is a behavioral design pattern that establishes a one-to-many dependency between objects. 
 * When the state of one object changes, all its dependent objects are automatically notified and updated. 
 * This pattern is useful when you want to maintain consistency between related objects without coupling them tightly.
 * 
 * In C++, you can implement the Observer pattern using a combination of subject and observer classes. 
 * Here's an example to illustrate the Observer pattern:
*/

#include <iostream>
#include <vector>
#include <algorithm>

// // Forward declaration of Observer class
// class Observer;

/**
 * The Observer class is an abstract base class that defines the update() method, which is called by the subject when its state changes.
*/

// Observer class
class Observer {
public:
    virtual void update() = 0;
};


/**
 * In this example, we have a Subject class and an Observer class. The Subject class has methods to attach and detach observers, 
 * as well as a method to notify all attached observers. 
 * It also defines pure virtual methods getState() and setState() that are used by ConcreteSubject to manage its state.
*/

// Subject class
class Subject {
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Remove the observer from the vector
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        // Notify all observers
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    virtual int getState() = 0;
    virtual void setState(int state) = 0;

private:
    std::vector<Observer*> observers;
};

