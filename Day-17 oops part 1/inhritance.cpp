#include<iostream>
#include<string>
using namespace std;

// single inheritanse

// class Animal{
// public:
//     string color;
//     void eat(){
//         cout<<"eats "<<endl;
//     }
//     void breath(){
//         cout<<"breaths "<<endl;
//     }
// };

// class Fish : public Animal{
//     public:
//   int fins;
//     void swim(){
//         cout<<"swims"<<endl;
//     }

// };

// multi inheritanse
// class Animal{
// public:
    
//     void eat(){
//         cout<<"eats "<<endl;
//     }
//     void breath(){
//         cout<<"breaths "<<endl;
//     }
// };

// class Mammal : public Animal{
//     public:
//         string blood;
//      Mammal(){
//        blood="warm"; 
//     }

// };

// class Dog : public Mammal{
//     public:
//     void tail(){
//         cout<<"dog"<<endl;
//     }
// };
// int main(){
//     Dog d1;

//     d1.eat();
//     d1.breath();
//     d1.tail();

//     cout<<d1.blood;
   

    
//     return 0;
// }

// multiple inheritanse;
class Teacher{
    public:
    int salary;
    string subject;
};

class Student{
    public:
    int rollno;
    float cgpa;
};

class TA:public Teacher,public Student{
    public:

     string name;

};


int main(){
    TA t1;
    t1.name="shradha Dubey";
    t1.subject="c++";
    t1.cgpa=9.1;

    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.cgpa<<endl;
    
    return 0;
}