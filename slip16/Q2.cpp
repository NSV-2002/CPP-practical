#include <iostream>
using namespace std;

// Base class Learn_Info
class Learn_Info {
protected:
    int Roll_No;
    string Stud_Name;
    string Class;
    float Percentage;

public:
    Learn_Info(int roll, string name, string cls, float perc) {
        Roll_No = roll;
        Stud_Name = name;
        Class = cls;
        Percentage = perc;
    }

    void displayLearnInfo() {
        cout << "Roll No: " << Roll_No << endl;
        cout << "Student Name: " << Stud_Name << endl;
        cout << "Class: " << Class << endl;
        cout << "Percentage: " << Percentage << "%" << endl;
    }
};

// Base class Earn_Info
class Earn_Info {
protected:
    int No_of_hours_worked;
    float Charges_per_hour;

public:
    Earn_Info(int hours, float charges) {
        No_of_hours_worked = hours;
        Charges_per_hour = charges;
    }

    float calculateEarnings() {
        return No_of_hours_worked * Charges_per_hour;
    }
};

// Derived class Earn_Learn_info
class Earn_Learn_info : public Learn_Info, public Earn_Info {
public:
    Earn_Learn_info(int roll, string name, string cls, float perc, int hours, float charges)
        : Learn_Info(roll, name, cls, perc), Earn_Info(hours, charges) {}

    void displayInfo() {
        displayLearnInfo();
        cout << "No of Hours Worked: " << No_of_hours_worked << endl;
        cout << "Charges per Hour: Rs." << Charges_per_hour << endl;
        cout << "Total Money Earned: Rs." << calculateEarnings() << endl;
    }
};

int main() {
    Earn_Learn_info student(101, "Rahul Sharma", "BCA", 85.5, 20, 150);
    student.displayInfo();
    return 0;
}
