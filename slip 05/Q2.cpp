#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string Book_name;
    string author;
    float price;

public:
    // Function to accept book details
    void input() {
        cin.ignore(); // Ignore newline character from previous input
        cout << "Enter book name: ";
        getline(cin, Book_name);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter book price: ";
        cin >> price;
    }

    // Function to display book details
    void display() {
        cout << "\nBook Name: " << Book_name;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: Rs. " << price << endl;
        cout << "----------------------" << endl;
    }

    // Function Overloading: Display books by author
    static void display(Book books[], int n, string searchAuthor) {
        cout << "\nBooks by author: " << searchAuthor << endl;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (books[i].author == searchAuthor) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found by this author.\n";
        }
    }

    // Function Overloading: Display books by price
    static void display(Book books[], int n, float searchPrice) {
        cout << "\nBooks with price Rs. " << searchPrice << ":\n";
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (books[i].price == searchPrice) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found at this price.\n";
        }
    }
};

int main() {
    int n;
    string searchAuthor;
    float searchPrice;

    cout << "Enter the number of books: ";
    cin >> n;

    Book books[n]; // Array of objects

    // Accepting book details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Book " << i + 1 << ":\n";
        books[i].input();
    }

    // Display all books
    cout << "\nAll Books:\n";
    for (int i = 0; i < n; i++) {
        books[i].display();
    }

    // Search books by author
    cin.ignore(); // Ignore newline character from previous input
    cout << "\nEnter author name to search: ";
    getline(cin, searchAuthor);
    Book::display(books, n, searchAuthor);

    // Search books by price
    cout << "\nEnter price to search: ";
    cin >> searchPrice;
    Book::display(books, n, searchPrice);

    return 0;
}
