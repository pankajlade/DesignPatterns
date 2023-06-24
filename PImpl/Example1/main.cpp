#include "User.h"
using namespace std;
int main()
{
    User obj("PANKAJ");
    obj.setSalary(100000);
    cout << obj.getSalary() << endl;
}