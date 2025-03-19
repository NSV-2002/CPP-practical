// Q2.Write a C++ program to create a class which contains two dimensional integer array of size m*n
// Write a member function to display transpose of entered matrix.(Use Dynamic Constructor for
// allocating memory and Destructor to free memory of an object).

#include<iostream>
using namespace std;

class Matrix{
    private:
    int **arr;
    int rows, cols;

    public:
       Matrix(int m, int n)
       {
        rows = m;
        cols = n;
        arr = new int* [rows];
        for(int i = 0; i < rows; i++){
            arr[i] = new int[cols];
        }
       }

       void inputMatrix(){
        cout<<"Enter the elements of the "<<rows<<"x"<<cols<<"matrix:\n";
        for(int i = 0; i<rows;i++){
            for(int j = 0; j < cols; j++){
                cin>>arr[i][j];
            }
        }
      }
       void displayMatrix(){
        cout<<"the elements of the "<<rows<<"x"<<cols<<"matrix are:\n";
        for(int i = 0; i<rows;i++){
            for(int j = 0; j < cols; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
      }
       void transposeMatrix(){
        cout<<"the transpose of the "<<rows<<"x"<<cols<<"matrix is:\n";
        for(int j = 0; j<cols;j++){
            for(int i = 0; i < rows; i++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
      }

      ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i]; // Free each row
        }
        delete[] arr; // Free row pointers
        cout << "Memory freed successfully.\n";
    }


};
int main(){
    int m,n;
    cout<<"Enter number of rows of matrix: ";
    cin>>m;
    cout<<"Enter number of cols of matix:";
    cin>>n;

    Matrix arr(m,n);

    arr.inputMatrix();
   arr.displayMatrix();
   arr.transposeMatrix();

    return 0;
}