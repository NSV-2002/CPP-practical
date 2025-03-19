#include <iostream>
using namespace std;

class Item {
private:
    int item_code;
    string item_name;
    float item_price;
    static int count; // Static data member to track number of objects

public:
    // Constructor to initialize item details
    Item() {
        count++; // Increment count when object is created
    }
    
    // Member function to accept item details
    void acceptDetails() {
        cout << "Enter Item Code: ";
        cin >> item_code;
        cout << "Enter Item Name: ";
        cin.ignore();
        getline(cin, item_name);
        cout << "Enter Item Price: ";
        cin >> item_price;
    }
    
    // Member function to display item details
    void displayDetails() const {
        cout << "Item Code: " << item_code << ", Name: " << item_name << ", Price: " << item_price << endl;
    }
    
    // Static function to display number of objects created
    static void displayCount() {
        cout << "Total Items Created: " << count << endl;
    }
};

// Initialize static data member
int Item::count = 0;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    
    Item items[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Item " << (i + 1) << ":" << endl;
        items[i].acceptDetails();
    }
    
    cout << "\nItem Details:\n";
    for (int i = 0; i < n; i++) {
        items[i].displayDetails();
    }
    
    // Display total items created
    Item::displayCount();
    
    return 0;
}