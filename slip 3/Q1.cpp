#include<iostream>
#include<cmath>

using namespace std;

double volume(double side){
    return pow(side,3);
}

double volume(double radius, double height)
{
    return M_PI*radius*radius*height;
}

double volume(double radius, int isSphere)
{
    return (4.0/3.0)*M_PI*pow(radius, 3);
}

int main(){

    int radius,height, side,choice;
    
while(true){
    cout<<"1. find the volume of cube :\n 2.find the volume of cylinder: \n 3.find the volume of sphere:\n 4.exit"<<endl;
    cout<<"Enter the choice (1/3):"<<endl;
    cin>> choice;
    if(choice == 1){
        cout<<"Enter the side of cube:"<<endl;
        cin>>side;

        cout<<"volume of cube is :"<<volume(side)<<endl;
        cout<<endl;

    }

    else if(choice == 2){
        cout<<"Enter the radius of cylinder:"<<endl;
        cin>>radius;
        cout<<"Enter the height of cylinder:"<<endl;
        cin>>height;
        cout<<"volume of cylinder is :"<<volume(radius, height)<<endl;
        cout<<endl;
    }

    else if(choice == 3){
        cout<<"Enter the radius of sphere:"<<endl;
        cin>>radius;
        cout<<"volume of cube is :"<<volume(radius,true)<<endl;
        cout<<endl;

    }

    else if(choice == 4){
        break;
    }

    else 
    {
        cout<<"enter valid input!!"<<endl;
        cout<<endl;

    }


}
cout<<"exiting program......"<<endl;
return 0;

}