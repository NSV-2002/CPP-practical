#include <iostream>
using namespace std;

// Function to swap two integers using call by reference
void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Function call to swap values
    swapNumbers(num1, num2);
    
    cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    return 0;
}