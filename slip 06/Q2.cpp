#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Base class Employee
class Employee {
public:
    string name;
    string designation;

    Employee(string n, string d) : name(n), designation(d) {}
};

// Base class Project
class Project {
public:
    int project_id;
    string title;

    Project(int id, string t) : project_id(id), title(t) {}
};

// Derived class Emp_Proj
class Emp_Proj : public Employee, public Project {
public:
    int duration; // Duration in months

    Emp_Proj(string n, string d, int id, string t, int dur) 
        : Employee(n, d), Project(id, t), duration(dur) {}

    void display() {
        cout << name << "\t" << designation << "\t" << project_id << "\t" << title << "\t" << duration << " months" << endl;
    }
};

// Function to display the master table
void displayMasterTable(vector<Emp_Proj>& records) {
    cout << "\nMaster Table:\n";
    cout << "Name\tDesignation\tProject ID\tTitle\tDuration" << endl;
    for (auto& record : records) {
        record.display();
    }
}

// Function to display projects sorted by duration
void displayProjectsByDuration(vector<Emp_Proj>& records) {
    sort(records.begin(), records.end(), [](Emp_Proj a, Emp_Proj b) {
        return a.duration < b.duration;
    });
    displayMasterTable(records);
}

int main() {
    vector<Emp_Proj> records;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Build Master Table\n";
        cout << "2. Display Master Table\n";
        cout << "3. Display Projects Sorted by Duration\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, designation, title;
            int id, duration;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Designation: ";
            cin >> designation;
            cout << "Enter Project ID: ";
            cin >> id;
            cout << "Enter Project Title: ";
            cin >> title;
            cout << "Enter Duration (in months): ";
            cin >> duration;
            records.push_back(Emp_Proj(name, designation, id, title, duration));
            break;
        }
        case 2:
            displayMasterTable(records);
            break;
        case 3:
            displayProjectsByDuration(records);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}