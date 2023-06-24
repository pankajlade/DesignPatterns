
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class User{

    // Internal Implementation
    class Impl;
    // Pointer to the internal implementation  
    std::unique_ptr<Impl> pImpl;
    
    public:
        User(std::string name);
        ~User();

        // Copy constructor 
        User(const User& obj);
        // Copy Assignment operator
        User& operator = (User & obj);
        
        void setSalary(int val);

        int getSalary();

};

