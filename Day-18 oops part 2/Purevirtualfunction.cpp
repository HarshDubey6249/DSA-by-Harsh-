#include<iostream>
using namespace std;

//abstract class
class Shape{
    public: 
    // void draw() //pure virtual function

     virtual  void draw() =0; //abstract function ,pure virtual function
};

class Circle:public Shape{
    public:
     void draw(){
        cout<<"draw circle function \n";

     }
};

class Square:public Shape{
    public:
     void draw(){
        cout<<"draw Square function";

     }
};

int main(){

    Circle c1;
    c1.draw();

    Square s1;
    s1.draw();
    return 0;
}