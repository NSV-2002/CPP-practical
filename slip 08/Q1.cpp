#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
    int numA;
public:
    ClassA(int a) : numA(a) {}

    // Declare friend function
    friend int subtract(ClassA, ClassB);
};

class ClassB {
    int numB;
public:
    ClassB(int b) : numB(b) {}

    // Declare friend function
    friend int subtract(ClassA, ClassB);
};

// Friend function definition
int subtract(ClassA a, ClassB b) {
    return a.numA - b.numB;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    ClassA objA(x);
    ClassB objB(y);

    cout << "Subtraction result: " << subtract(objA, objB) << endl;

    return 0;
}
