#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    // Function to simplify the fraction
    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    // Constructor to initialize fraction
    Fraction(int num, int denom) {
        if (denom == 0) {
            cout << "Denominator cannot be zero. Setting default value to 1." << endl;
            denom = 1;
        }
        numerator = num;
        denominator = denom;
        simplify();
    }

    // Overloading ++ (pre-increment)
    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    // Overloading -- (pre-decrement)
    Fraction& operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    // Overloading * operator for multiplication
    Fraction operator*(const Fraction& other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Function to display fraction
    void display() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(3, 4), f2(2, 5);
    
    cout << "Original Fractions:" << endl;
    cout << "f1: "; f1.display();
    cout << "f2: "; f2.display();
    
    ++f1;
    cout << "\nAfter Incrementing f1: ";
    f1.display();
    
    --f2;
    cout << "After Decrementing f2: ";
    f2.display();
    
    Fraction f3 = f1 * f2;
    cout << "\nMultiplication of f1 and f2: ";
    f3.display();
    
    return 0;
}