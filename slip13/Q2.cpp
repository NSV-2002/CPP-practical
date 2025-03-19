// Q2.Write a C++ program to read the contents of a text file. Count and display number of characters,
// words and lines from a file. Find the number of occurrences of a given word present in a file.
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string filename, word, searchWord;
    int charCount = 0, wordCount = 0, lineCount = 0, searchCount = 0;
    
    cout << "Enter filename: ";
    cin >> filename;
    cout << "Enter word to search: ";
    cin >> searchWord;
    
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    string line;
    while (getline(file, line)) {
        lineCount++;
        charCount += line.length();
        
        stringstream ss(line);
        while (ss >> word) {
            wordCount++;
            if (word == searchWord) {
                searchCount++;
            }
        }
    }
    file.close();
    
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    cout << "Occurrences of '" << searchWord << "': " << searchCount << endl;
    
    return 0;
}