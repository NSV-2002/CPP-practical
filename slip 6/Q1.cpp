// Q1.Write a C++ program to implement a class printdata to overload print function as follows:
// void print(int) - outputs value followed by the value of the integer.
// Eg. print(10) outputs - value 10
// void print(char *) – outputs value followed by the string in double quotes.
// Eg. print(“hi”) outputs value “hi” 

#include<iostream>
using namespace std;

class printdata{
    private:
    int num;
    char ch;
    public:

    void print(int num){
         cout<<"value:"<< num<<endl;;
    }
    
    void print( const char* ch){
        cout<< "value:\""<<ch<<"\""<<endl;  ;
   }
};
int main(){

    printdata p1;
    int num ;
    char ch ;

    p1.print(10);
    p1.print("hi");
}