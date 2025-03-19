#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string sourceFile, destinationFile;
    
    cout << "Enter the source file name: ";
    cin >> sourceFile;
    cout << "Enter the destination file name: ";
    cin >> destinationFile;
    
        
    ifstream source(sourceFile, ios::binary);
    ofstream destination(destinationFile, ios::binary);
    
    if (!source) {
        cout << "Error: Could not open source file." << endl;
        return 1;
    }
    
    if (!destination) {
        cout << "Error: Could not open destination file." << endl;
        return 1;
    }
    
    destination << source.rdbuf();
    
    cout << "File copied successfully." << endl;
    
    source.close();
    destination.close();
    
    return 0;
}
