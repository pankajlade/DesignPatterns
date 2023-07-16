#include <iostream>
#include <vector>
#include <algorithm>

// Forward declaration of Observer class
class Observer;

// Observer class
class Observer {
public:
    virtual void onNewEmployee(const std::string& employeeName) = 0;
};

// Subject class
class EmployeeManagementSystem {
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Remove the observer from the vector
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyNewEmployee(const std::string& employeeName) {
        // Notify all observers about a new employee
        for (Observer* observer : observers) {
            observer->onNewEmployee(employeeName);
        }
    }

private:
    std::vector<Observer*> observers;
};

// Concrete Observer class
class PayrollDepartment : public Observer {
public:
    void onNewEmployee(const std::string& employeeName) override {
        std::cout << "Payroll Department: New employee added - " << employeeName << std::endl;
        // Perform specific actions related to payroll
    }
};

class HRDepartment : public Observer {
public:
    void onNewEmployee(const std::string& employeeName) override {
        std::cout << "HR Department: New employee added - " << employeeName << std::endl;
        // Perform specific actions related to HR
    }
};

int main() {
    // Create the employee management system
    EmployeeManagementSystem empManagementSystem;

    // Create the observers (departments)
    PayrollDepartment payrollDept;
    HRDepartment hrDept;

    // Register the observers to the employee management system
    empManagementSystem.addObserver(&payrollDept);
    empManagementSystem.addObserver(&hrDept);

    // Add a new employee
    empManagementSystem.notifyNewEmployee("John Doe");

    // Remove the HR department observer
    empManagementSystem.removeObserver(&hrDept);

    // Add another new employee
    empManagementSystem.notifyNewEmployee("Jane Smith");

    return 0;
}
