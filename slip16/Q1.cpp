#include <iostream>
using namespace std;

class Number {
private:
    int num1, num2;

public:
    // Default constructor
    Number() {
        num1 = 0;
        num2 = 0;
    }

    // Parameterized constructor
    Number(int a, int b) {
        num1 = a;
        num2 = b;
    }

    // Member function to display the maximum number
    void displayMax() {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "Maximum: " << ((num1 > num2) ? num1 : num2) << endl;
    }
};

int main() {
    // Creating objects
    Number obj1; // Default constructor
    Number obj2(10, 20); // Parameterized constructor

    cout << "Object 1:" << endl;
    obj1.displayMax();
    
    cout << "\nObject 2:" << endl;
    obj2.displayMax();

    return 0;
}
