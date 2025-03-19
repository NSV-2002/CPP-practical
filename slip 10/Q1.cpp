#include <iostream>
using namespace std;

class Employee {
private:
    float salary;

public:
    // Constructor
    Employee(float s = 0) : salary(s) {}

    // Overload pre-decrement operator (--emp)
    Employee& operator--() {
        --salary;
        return *this;
    }

    // Overload post-decrement operator (emp--)
    Employee operator--(int) {
        Employee temp = *this;
        salary--;
        return temp;
    }

    // Display salary
    void display() const {
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp(50000);
    
    cout << "Initial Salary: ";
    emp.display();
    
    --emp; // Pre-decrement
    cout << "After Pre-Decrement: ";
    emp.display();
    
    emp--; // Post-decrement
    cout << "After Post-Decrement: ";
    emp.display();
    
    return 0;
}
