#include <iostream>
#include <algorithm>
using namespace std;

class College {
public:
    int college_id;
    string college_name;
    int establishment_year;
    string university_name;

    // Function to accept details
    void acceptDetails() {
        cout << "Enter College ID: ";
        cin >> college_id;
        cout << "Enter College Name: ";
        cin.ignore();
        getline(cin, college_name);
        cout << "Enter Establishment Year: ";
        cin >> establishment_year;
        cout << "Enter University Name: ";
        cin.ignore();
        getline(cin, university_name);
    }

    // Function to display details
    void displayDetails() {
        cout << college_id << "\t" << college_name << "\t" << establishment_year << "\t" << university_name << endl;
    }
};

// Function to display colleges by university
void displayByUniversity(College colleges[], int n, string university) {
    cout << "\nColleges under " << university << ":\n";
    cout << "ID\tName\tEst. Year\tUniversity\n";
    for (int i = 0; i < n; i++) {
        if (colleges[i].university_name == university) {
            colleges[i].displayDetails();
        }
    }
}

// Function to display colleges sorted by establishment year
void displayByEstablishmentYear(College colleges[], int n) {
    sort(colleges, colleges + n, [](College a, College b) {
        return a.establishment_year < b.establishment_year;
    });
    cout << "\nColleges Sorted by Establishment Year:\n";
    cout << "ID\tName\tEst. Year\tUniversity\n";
    for (int i = 0; i < n; i++) {
        colleges[i].displayDetails();
    }
}

int main() {
    int n, choice;
    cout << "Enter number of colleges: ";
    cin >> n;
    College colleges[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for College " << (i + 1) << ":\n";
        colleges[i].acceptDetails();
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Colleges by University\n";
        cout << "2. Display Colleges by Establishment Year\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string university;
            cout << "Enter University Name: ";
            getline(cin, university);
            displayByUniversity(colleges, n, university);
            break;
        }
        case 2:
            displayByEstablishmentYear(colleges, n);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
