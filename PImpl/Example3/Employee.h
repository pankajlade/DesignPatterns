#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Employe
{
    class EmployImpl;
    std::unique_ptr<EmployImpl> pImpl;

public:
    Employe(const std::string &nam, int sal);
    ~Employe();

    Employe(const Employe &obj);
    Employe(Employe &&obj);

    Employe &operator=(Employe &obj);
    Employe &operator=(Employe &&);
    void setDetails();
    void displayEmployeInfo();
};