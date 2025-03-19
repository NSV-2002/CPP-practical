#include <iostream>
using namespace std;

class Student {
public:
    // Function to return the maximum of two scores
    int maximum(int score1, int score2) {
        return (score1 > score2) ? score1 : score2;
    }

    // Function to return the maximum score from an array
    int maximum(int *a, int arrayLength) {
        int maxScore = a[0];
        for (int i = 1; i < arrayLength; i++) {
            if (a[i] > maxScore) {
                maxScore = a[i];
            }
        }
        return maxScore;
    }
};

int main() {
    Student s;
    
    // Testing maximum of two scores
    int score1, score2;
    cout << "Enter two student scores: ";
    cin >> score1 >> score2;
    cout << "Maximum of two scores: " << s.maximum(score1, score2) << endl;

    // Testing maximum score from an array
    int n;
    cout << "Enter the number of scores: ";
    cin >> n;
    int *scores = new int[n];
    cout << "Enter " << n << " scores: ";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    cout << "Maximum score from the array: " << s.maximum(scores, n) << endl;
    
    delete[] scores; // Free allocated memory
    return 0;
}