#include <iostream>
using namespace std;

class Number {
private:
    int a, b;

public:
    // Default constructor
    Number() {
        a = 0;
        b = 0;
    }

    // Parameterized constructor with default values
    Number(int x, int y = 10) {
        a = x;
        b = y;
    }

    // Function to display the maximum number
    void displayMax() {
        cout << "Max of " << a << " and " << b << " is: " << ((a > b) ? a : b) << endl;
    }
};

int main() {
    Number obj1;          // Calls default constructor
    Number obj2(15);      // Calls parameterized constructor (y defaults to 10)
    Number obj3(25, 30);  // Calls parameterized constructor with both values

    cout << "Object 1: ";
    obj1.displayMax();
    cout << "Object 2: ";
    obj2.displayMax();
    cout << "Object 3: ";
    obj3.displayMax();

    return 0;
}
