/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string & t) : title(t){}

    void add_entry(const string & entry){
        static int count = 1;
        entries.push_back(to_string(count++) + ": "  + entry);
    } 

    void save( const string & filename){
        ofstream ofs(filename);
        for(auto it : entries)
            ofs << it << endl;
    }
    
};

struct PersistenceManager{
    static void Save(const Journal & j, const string & filename){
        ofstream ofs(filename);
        for(auto it : j.entries)
            ofs << it << endl;
    }
};

int main()
{
    Journal journal{"Diary"};
    journal.add_entry("India is my Country.");
    journal.add_entry("India is Best.");

    // journal.Save("myFile.txt");
    PersistenceManager pm;
    pm.Save(journal,"my.txt");
}

*/

// ==========================================================================================// 
// 2nd Example 
// ==========================================================================================// 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Employee class responsible for employee information and printing
class Employee {
private:
    std::string name;
    int age;
    double salary;

public:
    Employee(const std::string& name, int age, double salary)
        : name(name), age(age), salary(salary) {}

    // Getter and setter methods for the employee attributes
    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double newSalary) {
        salary = newSalary;
    }

    // Print method responsible for displaying employee information
    void printInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }
};

// EmployeeDatabase class responsible for storing and managing employees
class EmployeeDatabase {
private:
    std::vector<Employee> employees;

public:
    // Add an employee to the database
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    // Remove an employee from the database
    void removeEmployee(const Employee& employee) {
        // Implementation to remove employee from the vector
        employees.erase(std::remove_if(employees.begin(), employees.end(), [employee](const Employee& emp) {
            return emp.getName() == employee.getName();
        }), employees.end());
    }

    // Retrieve an employee from the database by name
    Employee getEmployeeByName(const std::string& name) const {
        // Implementation to search for and return the employee
        auto it = std::find_if(employees.begin(),employees.end(),[name](const Employee & obj){
            return obj.getName() == name;
        });

        if(it != employees.end()){
            Employee myObj = *it;
            return myObj;
        }
        else{
            cout << "Employ not found ====> " << endl;
            return Employee("",0,0);
        }
    }

    // Display all employees' information
    void displayAllEmployees() const {
        for (const auto& employee : employees) {
            employee.printInfo();
            std::cout << "-----------------------------" << std::endl;
        }
    }
};

int main() {
    // Create an instance of the Employee class
    Employee john("John Doe", 30, 5000.0);
    Employee pankaj("Pankaj lade", 28, 18000.0);
    Employee darshan("Darshan sagwekar", 29, 15000.0);
    Employee vicky("vicky kale", 31, 22000.0);
    Employee daulat("Daulat yadav", 32, 20000.0);

    // Create an instance of the EmployeeDatabase class
    EmployeeDatabase database;

    // Add the employee to the database
    database.addEmployee(john);
    database.addEmployee(pankaj);
    database.addEmployee(darshan);
    database.addEmployee(vicky);
    database.addEmployee(daulat);

    // Display all employees' information
    database.displayAllEmployees();

    // Find element from vector
    Employee my = database.getEmployeeByName("vicky kale");
    cout << "=======================================" << endl;
    cout << my.getName() << " " << my.getAge() << " " << my.getSalary() << endl;

    // Remove element from vector
    cout << "=======================================" << endl;
    database.removeEmployee(darshan);
    database.displayAllEmployees();
    return 0;
}
/*
    In this example, we have two classes: Employee and EmployeeDatabase. 
    The Employee class is responsible for holding the information of an employee (name, age, and salary) 
    and printing the employee's information. The EmployeeDatabase class is responsible for storing and managing 
    the collection of employees.

    By separating the responsibilities of storing/managing employees and printing employee information into separate classes,
    we adhere to the Single Responsibility Principle. 
    If there are any changes required in the way employees are stored or managed, 
    or if there are changes needed in how employee information is printed, 
    we can modify the respective class without impacting the other.
*/