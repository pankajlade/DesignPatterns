#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer;

class Button{
    std::vector<Observer *> observers;
    public:
        void addObserver(Observer * obs);
        void removeObserver(Observer * obs);
        void click();
};


// Observer Interface;
class Observer{
    public :
        virtual void onClick() = 0;
};

// Concrete Observer (Listener)
class ButtonListener:public Observer{
    public:
        void onClick() override{
            cout << "Button Clicked . Action taken by ButtonListener" << endl;
        }
};

// Implementation of Button class 
void Button::addObserver(Observer * obs){
    observers.push_back(obs);
}

void Button::removeObserver(Observer * obs){
    // Remove Observer from the list.
    auto it = std::find(observers.begin(), observers.end(),obs);
    if(it != observers.end()){
        observers.erase(it);
    }
}

void Button::click(){
    // Notify all observers about click events.
    for(auto itr : observers){
        itr->onClick();
    }
}

int main()
{
    // creat a button and a listener.
    Button button;
    ButtonListener listener1, listener2;

    // Register the button to the listener
    button.addObserver(&listener1);
    button.addObserver(&listener2);

    // simulate a button click.
    button.click();

    // Unregister the listener from the button.
    button.removeObserver(&listener1);

    // simulate another button click
    button.click();
}