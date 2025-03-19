#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Department {
public:
    int Dept_Id;
    string Dept_Name, HOD;
    int Number_Of_Staff;

    void acceptDetails() {
        cout << "Enter Department ID: ";
        cin >> Dept_Id;
        cin.ignore(); // Clear input buffer
        cout << "Enter Department Name: ";
        getline(cin, Dept_Name);
        cout << "Enter HOD Name: ";
        getline(cin, HOD);
        cout << "Enter Number of Staff: ";
        cin >> Number_Of_Staff;
    }

    void writeToFile(ofstream &file) {
        file << Dept_Id << "," << Dept_Name << "," << HOD << "," << Number_Of_Staff << "\n";
    }

    static void displayFromFile() {
        ifstream inFile("Dept.txt");
        if (!inFile) {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        cout << "\nDepartment Details:\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
};

int main() {
    int n;
    cout << "Enter number of departments: ";
    cin >> n;

    ofstream outFile("Dept.txt");
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    vector<Department> departments(n);
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for department " << i + 1 << ":" << endl;
        departments[i].acceptDetails();
        departments[i].writeToFile(outFile);
    }
    outFile.close();

    // Display details from file
    Department::displayFromFile();

    return 0;
}