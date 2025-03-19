#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string sourceFile, destinationFile;
    
    cout << "Enter the source file name: ";
    cin >> sourceFile;
    cout << "Enter the destination file name: ";
    cin >> destinationFile;
    
    ifstream source(sourceFile, ios::binary);
    ofstream destination(destinationFile, ios::binary);
    #include <iostream>
using namespace std;

class Rectangle2; 

class Rectangle1 {
private:
    int length;
    int breadth;

public:
    void getDimension() {
        cout << "Enter length and breadth of Rectangle1: ";
        cin >> length >> breadth;
    }

    int area() const {
        return length * breadth;
    }

    friend void compare(const Rectangle1 &r1, const Rectangle2 &r2);
};

class Rectangle2 {
private:
    int length;
    int breadth; 

public:
    void getDimension() { 
        cout << "Enter length and breadth of Rectangle2: ";
        cin >> length >> breadth;
    }

    int area() const {
        return length * breadth;
    }


    friend void compare(const Rectangle1 &r1, const Rectangle2 &r2);
};


void compare(const Rectangle1 &r1, const Rectangle2 &r2) {
    cout << "Area of Rectangle1: " << r1.area() << endl;
    cout << "Area of Rectangle2: " << r2.area() << endl;

    if (r1.area() < r2.area()) {
        cout << r2.area() << " is greater." << endl;
    } else if (r1.area() > r2.area()) { 
        cout << r1.area() << " is greater." << endl;
    } else {
        cout << "Both rectangles have the same area." << endl;
    }
}

int main() {
    Rectangle1 r1; 
    r1.getDimension(); 

    Rectangle2 r2; 
    r2.getDimension();
    compare(r1, r2); 
    return 0;
}

    if (!source) {
        cout << "Error: Could not open source file." << endl;
        return 1;
    }
    
    if (!destination) {
        cout << "Error: Could not open destination file." << endl;
        return 1;
    }
    
    destination << source.rdbuf();
    
    cout << "File copied successfully." << endl;
    
    source.close();
    destination.close();
    
    return 0;
}
