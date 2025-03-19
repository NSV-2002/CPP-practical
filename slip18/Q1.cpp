#include <iostream>
using namespace std;

// Function to calculate the series sum
int seriesSum(int n) {
    int totalSum = 0;
    for (int i = 1; i <= n; i++) {
        totalSum += (i * (i + 1)) / 2; // Sum of first i natural numbers
    }
    return totalSum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    int result = seriesSum(n);
    cout << "Sum of the series: " << result << endl;
    
    return 0;
}