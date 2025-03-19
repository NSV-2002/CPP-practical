#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float percentage;

    void getData() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore(); // Clear newline character from input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void writeToFile(ofstream &file) {
        file << rollNo << "," << name << "," << percentage << "\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student student;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        student.getData();
        student.writeToFile(outFile);
    }

    outFile.close();
    cout << "Student information written to students.txt successfully!" << endl;
    
    return 0;
}