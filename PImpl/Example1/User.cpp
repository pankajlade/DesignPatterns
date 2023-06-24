#include "User.h"
#include <iostream>

using namespace std;

class User::Impl{
    public:
        std::string Name{""};
        int salary{0};
        Impl(std::string name):Name{std::move(name)}{
            cout << "Impl Parameterized COnstructor" << endl;
        }

        ~Impl(){
            cout << "Impl Destructor" << endl;
        }

        void setSalary(int Sal){
            salary = Sal;
        }

        int getSalary(){
            return salary;
        }
};

User::User(std::string name)
    : pImpl(make_unique<Impl>(std::move(name)))
{  
    cout << "User Constructor" << endl;
}

User::~User()
{
    cout << "User Destructor " << endl;
}

User::User(const User & obj):pImpl(make_unique<Impl>(*obj.pImpl)){
    cout << "User Copy Constructor" << endl;
}

User & User::operator =( User & obj ){
    
    swap(pImpl, obj.pImpl);
    return *this;
}

void User::setSalary(int val){
    
    pImpl->setSalary(val);
}

int User::getSalary(){
    return pImpl->getSalary();
}