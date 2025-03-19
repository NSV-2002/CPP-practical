/* Q1.Write a C++ program to create a class Mobile which contains data members as Mobile_Id,
 Mobile_Name, Mobile_Price. Create and Initialize all values of Mobile object by using
 parameterized constructor. Display the values of Mobile object.*/
#include<iostream>
using namespace std;

class Mobile{
    private:
    int Mobile_Id;
    string Mobile_Name;
    double Mobile_Price;

    public:
       Mobile(int id, string Name ,double Price)
       {
          Mobile_Id = id;
          Mobile_Name = Name;
          Mobile_Price = Price;
       }

      void display(){
         cout<<"mobile_id:"<<Mobile_Id<<endl;
         cout<<"mobile_name:"<<Mobile_Name<<endl;
         cout<<"mobile_price:"<<Mobile_Price<<endl;
      }
};

int main(){

    int id;
    string name;
    double price;
    cout<<"enter mobile id:";
    cin>>id;
    cout<<"enter mobile name:";
    cin>>name;
    cout<<"enter mobile price:";
    cin>>price;

    Mobile m1(id,name,price);

    m1.display();
   return 0;
}
