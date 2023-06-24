#include "Employe.h"

class Employe::EmployImpl
{

    std::string name;
    int salary;

public:
    EmployImpl(const std::string &nam, int sal) : name{nam}, salary{sal}
    {
        cout << "Employ Imple Constructor" << endl;
    }
    ~EmployImpl()
    {
        cout << "Employ Imple Destructor" << endl;
    }

    void setDetails()
    {
        cout << "SET DETAILS " << endl;
    }

    void displayEmployInfo()
    {
        cout << "Employe Name : " << name << endl;
        cout << "Employe Salary : " << salary << endl;
    }
};

Employe::Employe(const std::string &nam, int sal) : pImpl{make_unique<EmployImpl>(nam, sal)}
{
    cout << "Employe Constructor" << endl;
}

Employe::~Employe()
{
    cout << "Employe Destructor" << endl;
}

void Employe::setDetails()
{
    pImpl->setDetails();
}

void Employe::displayEmployeInfo()
{
    pImpl->displayEmployInfo();
}

Employe::Employe(const Employe &obj) : pImpl{make_unique<EmployImpl>(*obj.pImpl)}
{
    cout << "Employe Copy Constructor " << endl;
}

Employe::Employe(Employe &&obj) : pImpl{std::move(obj.pImpl)}
{
    cout << "Employe Move Constructor" << endl;
}

Employe &Employe::operator=(Employe &obj)
{
    cout << "Copy Assignment Operator Overload " << endl;
    std::swap(pImpl, obj.pImpl);
    return *this;
}

Employe &Employe::operator=(Employe &&obj)
{
    cout << "Move Assignment operator overload " << endl;
    pImpl = std::move(obj.pImpl);
    return *this;
}