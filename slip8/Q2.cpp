#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;

public:
    // Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overloading ! operator to reverse case of each alphabet
    void operator!() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
            else if (islower(str[i]))
                str[i] = toupper(str[i]);
        }
    }

    // Overloading == operator to check equality of two strings
    bool operator==(const String& s) {
        return strcmp(str, s.str) == 0;
    }

    // Function to display string
    void display() {
        cout << str << endl;
    }
};

int main() {
    String s1("HelloWorld");
    String s2("HELLOworld");

    cout << "Original String 1: ";
    s1.display();

    !s1; // Reverse case
    cout << "After using ! operator: ";
    s1.display();

    if (s1 == s2)
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;

    return 0;
}