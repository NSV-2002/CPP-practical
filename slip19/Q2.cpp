#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Base class Employee
class Employee {
protected:
    string Name, Designation;
public:
    Employee(string name, string designation) {
        Name = name;
        Designation = designation;
    }
};

// Base class Project
class Project {
protected:
    int Project_Id;
    string Title;
public:
    Project(int id, string title) {
        Project_Id = id;
        Title = title;
    }
};

// Derived class Emp_Proj
class Emp_Proj : public Employee, public Project {
public:
    int Duration;

    Emp_Proj(string name, string designation, int id, string title, int duration)
        : Employee(name, designation), Project(id, title) {
        Duration = duration;
    }

    void display() {
        cout << "Name: " << Name << " | Designation: " << Designation
             << " | Project ID: " << Project_Id << " | Title: " << Title
             << " | Duration: " << Duration << " days" << endl;
    }
};

// Function to display menu
void menu(vector<Emp_Proj> &records) {
    int choice;
    do {
        cout << "\nMenu:\n1. Build Master Table\n2. Display Master Table\n3. Display Projects (Sorted by Duration)\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, designation, title;
                int id, duration;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Designation: "; getline(cin, designation);
                cout << "Enter Project ID: "; cin >> id;
                cin.ignore(); // Clear input buffer
                cout << "Enter Project Title: "; getline(cin, title);
                cout << "Enter Duration (in days): "; cin >> duration;
                records.push_back(Emp_Proj(name, designation, id, title, duration));
                break;
            }
            case 2:
                cout << "\nMaster Table:\n";
                for (const auto &record : records) {
                    record.display();
                }
                break;
            case 3:
                sort(records.begin(), records.end(), [](Emp_Proj &a, Emp_Proj &b) {
                    return a.Duration < b.Duration;
                });
                cout << "\nProjects Sorted by Duration:\n";
                for (const auto &record : records) {
                    record.display();
                }
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    vector<Emp_Proj> records;
    menu(records);
    return 0;
}