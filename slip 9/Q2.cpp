#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Function to read time
    void readTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
        
        // Normalize time
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }
    
    // Function to display time in hh:mm:ss format
    void displayTime() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    
    // Function to add two time objects
    Time addTime(const Time& t) {
        Time result;
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours;
        
        // Normalize time
        if (result.seconds >= 60) {
            result.minutes += result.seconds / 60;
            result.seconds %= 60;
        }
        if (result.minutes >= 60) {
            result.hours += result.minutes / 60;
            result.minutes %= 60;
        }
        return result;
    }
};

int main() {
    Time t1, t2, t3;
    
    cout << "Enter first time:\n";
    t1.readTime();
    
    cout << "Enter second time:\n";
    t2.readTime();
    
    cout << "\nFirst Time: ";
    t1.displayTime();
    
    cout << "Second Time: ";
    t2.displayTime();
    
    t3 = t1.addTime(t2);
    
    cout << "\nSum of Times: ";
    t3.displayTime();
    
    return 0;
}