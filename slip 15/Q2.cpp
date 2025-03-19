#include <iostream>
using namespace std;

// Base class with a pure virtual function
class Conversion {
public:
    virtual void read() = 0;
    virtual void convert() = 0;
    virtual void display() = 0;
};

// Derived class for Weight Conversion
class Weight : public Conversion {
    float grams, kilograms;
public:
    void read() {
        cout << "Enter weight in grams: ";
        cin >> grams;
    }
    void convert() {
        kilograms = grams / 1000.0;
    }
    void display() {
        cout << "Weight: " << grams << " g = " << kilograms << " kg" << endl;
    }
};

// Derived class for Volume Conversion
class Volume : public Conversion {
    float milliliters, liters;
public:
    void read() {
        cout << "Enter volume in milliliters: ";
        cin >> milliliters;
    }
    void convert() {
        liters = milliliters / 1000.0;
    }
    void display() {
        cout << "Volume: " << milliliters << " mL = " << liters << " L" << endl;
    }
};

// Derived class for Currency Conversion
class Currency : public Conversion {
    int rupees, paise;
public:
    void read() {
        cout << "Enter amount in rupees: ";
        cin >> rupees;
    }
    void convert() {
        paise = rupees * 100;
    }
    void display() {
        cout << "Currency: Rs. " << rupees << " = " << paise << " paise" << endl;
    }
};

int main() {
    Conversion *c;
    Weight w;
    Volume v;
    Currency cur;

    cout << "\nWeight Conversion:\n";
    c = &w;
    c->read();
    c->convert();
    c->display();

    cout << "\nVolume Conversion:\n";
    c = &v;
    c->read();
    c->convert();
    c->display();

    cout << "\nCurrency Conversion:\n";
    c = &cur;
    c->read();
    c->convert();
    c->display();
    
    return 0;
}  