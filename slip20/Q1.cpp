#include <iostream>
#include <algorithm>
using namespace std;

// Function to sort an integer array
void sortArray(int arr[], int size) {
    sort(arr, arr + size);
    cout << "Sorted Integer Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to sort a float array
void sortArray(float arr[], int size) {
    sort(arr, arr + size);
    cout << "Sorted Float Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArr[] = {5, 2, 9, 1, 6};
    float floatArr[] = {4.2, 2.5, 9.1, 1.8, 6.3};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    sortArray(intArr, intSize);
    sortArray(floatArr, floatSize);
    
    return 0;
}