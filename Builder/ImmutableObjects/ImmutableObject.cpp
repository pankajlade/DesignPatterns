#if 0
Certainly! In the context of immutable objects, the Builder pattern is often used to create objects where all the properties 
are set during the construction and cannot be modified afterward. This ensures that the object's state remains consistent and cannot be changed, 
leading to more predictable and thread-safe code.

Let's consider an example where we want to create an immutable Person class with properties like name, age, and address. 
Once a Person object is created, its state should not be modified. We can use the Builder pattern to achieve this by setting all 
the properties during the object's construction.
#endif

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person{
    std::string name{};
    int age{};
    std::string adderess{};
    public:
        Person(const std::string myName, 
        int myAge, 
        const std::string myAdderss)
        : name{myName},
          age{myAge},
          adderess{myAdderss}{
            cout << __func__ << endl;
          }

        std::string getName(){ return name;}
        int getAge(){ return age;}
        std::string getAdderess(){ return adderess;}
};

class PersonBuilder{
    std::string name;
    int age;
    std::string adderss;
    public: 
        Person build() const{
            return Person(name, age,adderss);
        }
        PersonBuilder& setName(const std::string Name){
            name = Name;
            return *this;
        }
        PersonBuilder& setAge(int Age){
            age = Age;
            return *this;
        }
        PersonBuilder& setAdderss(const std::string Adderess){
            adderss = Adderess;
            return *this;
        }
};


int main()
{
    Person person = PersonBuilder()
                        .setName("Vicky Kale")
                        .setAge(30)
                        .setAdderss("Ville-parle West")
                        .build();

    std::string name = person.getName();;
    int age = person.getAge();
    std::string adder = person.getAdderess();

    cout << "Name : " << name << endl;
    cout << "Age : " << age << endl;
    cout << "Adderess : " << adder << endl;
}
