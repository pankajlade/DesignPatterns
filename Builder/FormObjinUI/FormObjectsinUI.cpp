#include <iostream>
#include <string>
#include <memory>

using namespace std;
// Product class (Form)
class Form {
    std::string name_;
    std::string email_;
    std::string phoneNumber_;
    public:
        void setName(const std::string & name){
            name_ = name;
        }
        void setEmail(const std::string & email){
            email_ = email;
        }
        void setPhoneNumber(const std::string & number){
            phoneNumber_ = number;
        }

        void display(){
            cout << "Name : " << name_ << endl;
            cout << "Email : " << email_ << endl;
            cout << "PhoneNumeber : " << phoneNumber_ << endl;
        }
};

// Abstract builder class
class FormBuilder{
    public:
        virtual ~FormBuilder() = default;
        virtual void setName(const std::string &) = 0;
        virtual void setEmail(const std::string &) = 0;
        virtual void setPhoneNumber(const std::string &) = 0;
        virtual std::shared_ptr<Form> getForm() = 0;
};

// Concrete Builder class
class ConcreteFormBuilder : public FormBuilder{
    std::shared_ptr<Form> form_;
    public:
        ConcreteFormBuilder(){
            form_ = make_shared<Form>();
        }
        void setName(const std::string & name) override{
            form_->setName(name);
        }
        void setEmail(const std::string & email) override{
            form_->setEmail(email);
        }
        void setPhoneNumber(const std::string & number) override{
            form_->setPhoneNumber(number);
        }

        std::shared_ptr<Form> getForm() override{
            return form_;
        }
};

// Director class
class FormDirector{
    public:
        std::shared_ptr<Form> createForm(FormBuilder * builder ,
                                            const std::string& name,
                                            const std::string& email,
                                            const std::string& number){
                                                builder->setName(name);
                                                builder->setEmail(email);
                                                builder->setPhoneNumber(number);
                                                return builder->getForm();
                                            }
};

int main(){
    ConcreteFormBuilder builder;
    FormDirector director;

    std::string name = "John  Deere";
    std::string email = "xyz@yahoo.com";
    std::string number = to_string(1234567890);

    std::shared_ptr<Form> form = director.createForm(&builder, name, email, number);
    form->display();
}

#if 0
In this example, the Form class is the product that we want to build. 
The FormBuilder is an abstract class providing interfaces for setting form fields, and ConcreteFormBuilder 
is a concrete builder implementing the FormBuilder interface. The FormDirector class constructs the Form object using the builder.
#endif