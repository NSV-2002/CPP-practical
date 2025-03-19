#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    // Dynamic Constructor to allocate memory
    Array(int n) {
        size = n;
        arr = new int[size];
    }

    // Function to accept array elements
    void acceptElements() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Function to calculate and display median
    void displayMedian() {
        sort(arr, arr + size);
        double median;
        if (size % 2 == 0)
            median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        else
            median = arr[size / 2];
        
        cout << "Median: " << median << endl;
    }

    // Destructor to free memory
    ~Array() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    Array obj(n);
    obj.acceptElements();
    obj.displayMedian();
    
    return 0;
}