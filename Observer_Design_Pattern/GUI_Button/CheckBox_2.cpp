
/*
    Let's create a more complex GUI component using the Observer design pattern. 
    In this example, we'll create a "Checkbox" GUI component that can be observed
    by multiple observers, and we'll have two different types of observers: "Logger" and "Notifier".

    The "Checkbox" class will maintain its state (checked or unchecked) and 
    notify all registered observers whenever its state changes 
    (i.e., when it's checked or unchecked). The "Logger" observer will log the state changes to the console, 
    and the "Notifier" observer will display a notification message.
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

// Observer Interface
class Observer{
    public:
        virtual void update(bool checked) = 0;
};

// Subject interface (Observable)
class Checkbox{
    bool checked;
    std::vector<Observer *> observers;

    public:
    Checkbox():checked(false){}

    void addObserver(Observer * obs){
        observers.push_back(obs);
    }

    void removeObservers(Observer * obs){
        
        auto it = std::find(observers.begin(),observers.end(),obs);
        if(it != observers.end()){
            observers.erase(it);
        }
    }

    void check(){
        if(!checked){
            checked = true;
            // Notify all observers about the state change.
            for(Observer * itobs : observers){
                itobs->update(checked);
            }
        }
    }

    void unCheck(){
        if(checked){
            checked = false;
            // Notify all observers about the state chage.
            for(Observer * itobs : observers ){
                itobs->update(checked);
            }
        }
    }
};

// Concrete Observer : Logger
class Logger : public Observer {
    public:
        void update(bool checked) override {
            cout << "Logger ; checkbox state changed . checked : " << checked << endl;
        }
};

// concrete Observer : Notifier
class Notifier : public Observer{

        void displayNotification(const std::string & msg){
            cout << "Notification : " << msg << endl;
        }
    public:
        void update (bool checked ) override {
            if(checked){
                displayNotification("Checkbox is checked!");
            }
            else{
                displayNotification("Checkbox is UNChecked!");
            }
        }
};


int main(){
    // Create a checkbox and 2 observers.
    Checkbox checkbox;
    Logger logger;
    Notifier notifier;

    // Register the observers to the checkbox.
    checkbox.addObserver(&logger);
    checkbox.addObserver(&notifier);
    
    // Simulate checkbox interactions.
    checkbox.check();
    checkbox.unCheck();

    // Unregister the notifier interactions
    checkbox.removeObservers(&notifier);

    checkbox.check();
}

/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


class User{
    public:
        virtual void update(const std::string & msg)=0;
};

class Channel{
    vector<User *> observers;
    public: 
        void addSubscriber(User * obs){
            observers.push_back(obs);
        }

        void removeSubscriber(User * obs){
            auto it = std::find(observers.begin(),observers.end(), obs);
            if(it != observers.end()){
                observers.erase(it);
            }
        }

        void notifyObserver(const std::string & msg){
            for(auto itobs : observers){
                itobs->update(msg);
            }
        }
};

class AmanDukan : public User{
    public:
        void update(const std::string & msg){
            cout << "Aman : " << msg << endl;
        }
};

class KiranDukan : public User{
    public:
        void update(const std::string & msg){
            cout << "kiran : " << msg << endl;
        }
};


class VickyDukan : public User{
    public:
        void update(const std::string & msg){
            cout << "Vicky : " << msg << endl;
        }
};

class ChannelUpdate : public Channel{
    public:
        void updateStatus(const std::string &msg){
            notifyObserver(msg);
        }
};

int main()
{
    std::shared_ptr<ChannelUpdate> myChannel = make_shared<ChannelUpdate>();
    AmanDukan  aman ;
    KiranDukan kiran ;
    VickyDukan vicky ;

    myChannel->addSubscriber(&aman);
    myChannel->addSubscriber(&kiran);
    myChannel->addSubscriber(&vicky);

    myChannel->updateStatus("New member is added.");

    myChannel->removeSubscriber(&vicky);

    myChannel->updateStatus("One Member is removed.");

    
}

*/