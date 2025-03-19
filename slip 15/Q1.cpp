#include <iostream>
using namespace std;

// Inline function to find the minimum of two numbers
inline int min(int a, int b) {
    return (a < b) ? a : b;
}

// Inline function to find the maximum of two numbers
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "Minimum: " << min(num1, num2) << endl;
    cout << "Maximum: " << max(num1, num2) << endl;
    
    return 0;
}