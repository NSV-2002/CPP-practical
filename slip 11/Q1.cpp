#include <iostream>
using namespace std;

class Arithmetic {
private:
    float num1, num2;

public:
    // Constructor to initialize numbers
    Arithmetic(float a, float b) : num1(a), num2(b) {}

    // Inline functions for arithmetic operations
    inline float add() { return num1 + num2; }
    inline float subtract() { return num1 - num2; }
    inline float multiply() { return num1 * num2; }
    inline float divide() { return (num2 != 0) ? (num1 / num2) : 0; }

    // Function to display results
    void displayResults() {
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        if (num2 != 0)
            cout << "Division: " << divide() << endl;
        else
            cout << "Division: Undefined (Cannot divide by zero)" << endl;
    }
};

int main() {
    float a, b;
    cout << "Enter two float numbers: ";
    cin >> a >> b;
    
    Arithmetic obj(a, b);
    obj.displayResults();
    
    return 0;
}