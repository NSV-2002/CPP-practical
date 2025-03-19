#include <iostream>
using namespace std;

// Abstract class Student
class Student {
protected:
    int rollNo;
    string name;

public:
    // Constructor without initializer list
    Student(int r, const string& n) {
        rollNo = r;  // Assigning values inside constructor
        name = n;
    }

    // Pure virtual function
    virtual void display() = 0; // Making Student an abstract class

    virtual ~Student() {} // Virtual destructor to ensure proper cleanup
};

// Derived class Engineering
class Engineering : public Student {
public:
    Engineering(int r, const string& n) : Student(r, n) {}

    void display() override {
        cout << "Engineering Student - Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

// Derived class Medicine
class Medicine : public Student {
public:
    Medicine(int r, const string& n) : Student(r, n) {}

    void display() override {
        cout << "Medicine Student - Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

// Derived class Science
class Science : public Student {
public:
    Science(int r, const string& n) : Student(r, n) {}

    void display() override {
        cout << "Science Student - Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

int main() {
    // Array of pointers to base class Student
    Student* students[3];

    // Creating objects of derived classes and storing them in the array
    students[0] = new Engineering(101, "Alice");
    students[1] = new Medicine(102, "Bob");
    students[2] = new Science(103, "Charlie");

    cout << "\n📌 Student Details:\n----------------------\n";

    // Accessing objects via base class pointers
    for (int i = 0; i < 3; i++) {
        students[i]->display();
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        delete students[i];
    }

    return 0;
}
