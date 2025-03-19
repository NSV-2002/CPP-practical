#include <iostream>
#include <iomanip>
using namespace std;

class Product {
protected:
    int product_id;
    string product_name;
    float price;

public:
    Product(int id = 0, string name = "", float p = 0.0) : product_id(id), product_name(name), price(p) {}
    
    virtual void display() const {
        cout << left << setw(10) << product_id << setw(20) << product_name << setw(10) << fixed << setprecision(2) << price;
    }
    
    float getPrice() const {
        return price;
    }
};

class Discount : public Product {
private:
    float discount_percentage;

public:
    Discount(int id = 0, string name = "", float p = 0.0, float discount = 0.0)
        : Product(id, name, p), discount_percentage(discount) {}
    
    float getDiscountAmount() const {
        return (price * discount_percentage) / 100;
    }
    
    float getFinalPrice() const {
        return price - getDiscountAmount();
    }
    
    void display() const override {
        Product::display();
        cout << setw(10) << discount_percentage << setw(10) << getFinalPrice() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    
    Discount products[n];
    float total_price = 0.0, total_discount = 0.0;
    
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        float price, discount;
        
        cout << "\nEnter details for Product " << (i + 1) << ":\n";
        cout << "Product ID: ";
        cin >> id;
        cout << "Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Discount (%): ";
        cin >> discount;
        
        products[i] = Discount(id, name, price, discount);
        total_price += price;
        total_discount += products[i].getDiscountAmount();
    }
    
    cout << "\nBill Summary:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Discount" << setw(10) << "Final Price" << endl;
    cout << string(60, '-') << endl;
    
    for (int i = 0; i < n; i++) {
        products[i].display();
    }
    
    cout << string(60, '-') << endl;
    cout << "Total Price: " << fixed << setprecision(2) << total_price << endl;
    cout << "Total Discount: " << fixed << setprecision(2) << total_discount << endl;
    cout << "Final Amount Payable: " << fixed << setprecision(2) << (total_price - total_discount) << endl;
    
    return 0;
}