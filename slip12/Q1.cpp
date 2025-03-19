#include <iostream>
using namespace std;

class Rectangle {
private:
    float length, width;

public:
    // Constructor to initialize length and width
    Rectangle(float l, float w) : length(l), width(w) {}

    // Inline function to calculate area
    inline float area() { return length * width; }

    // Inline function to calculate perimeter
    inline float perimeter() { return 2 * (length + width); }

    // Function to display results
    void displayResults() {
        cout << "Area of Rectangle: " << area() << endl;
        cout << "Perimeter of Rectangle: " << perimeter() << endl;
    }
};

int main() {
    float length, width;
    cout << "Enter length and width of the rectangle: ";
    cin >> length >> width;
    
    Rectangle rect(length, width);
    rect.displayResults();
    
    return 0;
}
