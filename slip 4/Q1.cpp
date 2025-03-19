#include<iostream>
#include<cmath>
using namespace std;

inline double Areacircle(double radius){
    return M_PI*pow(radius,2);
}

inline double Areasquare(double side){
    return pow(side,2);
}

inline double Arearectangle(double lenght, double breadth){
    return lenght * breadth;
}

int main(){
   double radius, lenght, breadth, side;
   int choice;
   while(true){

    cout<<"1. Find the area of circle:"<<endl;
    cout<<"2. Find the area of square:"<<endl;
    cout<<"3. Find the area of rectangle:"<<endl;
    cout<<"4. Exit:"<<endl;
    cout<<"Enter your choice :";
    cin>> choice;

    switch(choice)
    {
        case 1:{
            cout<<"Enter the radius of circle:";
            cin>>radius;
            cout<<"Area of circle is :"<<Areacircle(radius)<<endl;
            cout<<endl;
            break;
        }

        case 2:{
            cout<<"Enter the side of square:";
            cin>>side;
            cout<<"Area of square is :"<<Areasquare(side)<<endl;
            cout<<endl;
            break;
        }

        case 3:{
            cout<<"Enter the lenght and breadth of rectangle:";
            cin>>lenght>>breadth;
            cout<<"Area of rectangle is :"<<Arearectangle(lenght,breadth)<<endl;
            cout<<endl;
            break;
        }

        case 4:{
            cout<<"Exiting program!!!"<<endl;
            return 0;
        }

        default:{
            cout<<"error: Invalid input!!!"<<endl;
        }
    }
    
   }
   return 0;
}