#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Bus {
public:
    int busNo;
    string busName;
    int noOfSeats;
    string startPoint;
    string destination;

    // Function to accept bus details
    void acceptDetails() {
        cout << "Enter Bus No: ";
        cin >> busNo;
        cin.ignore();
        cout << "Enter Bus Name: ";
        getline(cin, busName);
        cout << "Enter Number of Seats: ";
        cin >> noOfSeats;
        cin.ignore();
        cout << "Enter Starting Point: ";
        getline(cin, startPoint);
        cout << "Enter Destination: ";
        getline(cin, destination);
    }

    // Function to display bus details
    void displayDetails() {
        cout << left << setw(10) << busNo << setw(20) << busName << setw(15) << noOfSeats
             << setw(20) << startPoint << setw(20) << destination << endl;
    }
};

// Function to display buses from specified route
void displayByRoute(vector<Bus> &buses, string start, string end) {
    cout << "\nBuses from " << start << " to " << end << ":\n";
    cout << left << setw(10) << "Bus No" << setw(20) << "Bus Name" << setw(15) << "Seats"
         << setw(20) << "Start Point" << setw(20) << "Destination" << endl;
    for (const auto &bus : buses) {
        if (bus.startPoint == start && bus.destination == end) {
            bus.displayDetails();
        }
    }
}

int main() {
    int n, choice;
    cout << "Enter number of buses: ";
    cin >> n;
    vector<Bus> buses(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Bus " << (i + 1) << ":\n";
        buses[i].acceptDetails();
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display All Bus Details\n";
        cout << "2. Display Buses by Route\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "\nAll Bus Details:\n";
            cout << left << setw(10) << "Bus No" << setw(20) << "Bus Name" << setw(15) << "Seats"
                 << setw(20) << "Start Point" << setw(20) << "Destination" << endl;
            for (const auto &bus : buses) {
                bus.displayDetails();
            }
            break;
        case 2: {
            string start, end;
            cout << "Enter Starting Point: ";
            getline(cin, start);
            cout << "Enter Destination: ";
            getline(cin, end);
            displayByRoute(buses, start, end);
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}