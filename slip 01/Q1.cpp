// Q1.Write the definition for a class Cylinder that contains data members radius and height. The class
// has the following member functions:
// a. void setradius(float) to set the radius of data member.
// b. void setheight(float) to set the height of data member.
// c. float volume( ) to calculate and return the volume of the cylinder.
// Write a C++ program to create cylinder object and display its volume.

#include<iostream>
using namespace std;

class cylinder {

public:
 float radius;
 float height;

 void setradius(float r)
 {
    radius = r;
 }
 void setheight(float h)
 {
    height = h;
 }
 float volume()
 {
    return 3.14*radius*radius*height;
 }

};

int main()
{
    float r,h;

    cylinder v1;
    cout << "enter the radius of cylinder"<<endl;
    cin >> r;

    cout << "enter the height of cylinder"<<endl;
    cin >> h;
    v1.setradius(r);
    v1.setheight(h);
    cout << "volume of cylinder :"<< v1.volume()<<endl;
}