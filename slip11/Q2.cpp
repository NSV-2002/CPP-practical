#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string city;
    string mobile_no;

public:
    // Function to accept person details
    void acceptDetails() {
        cout << "Enter Person Name: ";
        getline(cin, name);
        cout << "Enter City: ";
        getline(cin, city);
        cout << "Enter Mobile Number: ";
        getline(cin, mobile_no);
    }

    // Function to display person details
    void displayDetails() const {
        cout << "Name: " << name << ", City: " << city << ", Mobile No: " << mobile_no << endl;
    }

    // Function to search by mobile number
    bool search(string mobile) const {
        return mobile_no == mobile;
    }

    // Function to search by city
    bool searchByCity(string search_city) const {
        return city == search_city;
    }
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;
    cin.ignore();
    
    Person persons[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Person " << (i + 1) << ":\n";
        persons[i].acceptDetails();
    }
    
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display All Persons\n";
        cout << "2. Search by Mobile Number\n";
        cout << "3. Search by City\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "\nPerson Details:\n";
                for (int i = 0; i < n; i++) {
                    persons[i].displayDetails();
                }
                break;
            
            case 2: {
                string mobile;
                cout << "Enter Mobile Number to search: ";
                getline(cin, mobile);
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (persons[i].search(mobile)) {
                        persons[i].displayDetails();
                        found = true;
                    }
                }
                if (!found) cout << "No person found with this mobile number.\n";
                break;
            }
            
            case 3: {
                string search_city;
                cout << "Enter City to search: ";
                getline(cin, search_city);
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (persons[i].searchByCity(search_city)) {
                        persons[i].displayDetails();
                        found = true;
                    }
                }
                if (!found) cout << "No person found in this city.\n";
                break;
            }
            
            case 4:
                cout << "Exiting...\n";
                break;
            
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}