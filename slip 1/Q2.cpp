// Write a C++ program to create a class Array that contains one float array as member. Overload
// the Unary ++ and -- operators to increase or decrease the value of each element of an array. Use
// friend function for operator function. 

#include<iostream>
using namespace std;

class Array{
    private:
    static const int size = 5 ;
    float array[size];
    public:
    void getarr()
    {
        cout<<"Enter the elements of array: "<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>array[i];
        }
    }

    void display(){
        for(int i=0;i<size;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    friend void operator++(Array &arr);
    friend void operator--(Array &arr);
};

void operator++(Array &arr)
{
    for(int i=0;i<Array::size;i++)
    {
        arr.array[i] += 1.0; 
    }
}

void operator--(Array &arr)
{
    for(int i=0;i<Array::size;i++)
    {
        arr.array[i] -= 1.0; 
    }
}

int main()
{
    Array arr;

    arr.getarr();

    cout<<"original array:"<<endl;
    arr.display();

    cout<<"Array after incrementing "<<endl;
    ++arr;
    arr.display();
    
    cout<<"Array after decrementing "<<endl;
    --arr;
    arr.display();
    

}