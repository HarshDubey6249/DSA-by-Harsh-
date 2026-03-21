#include<iostream>
using namespace std;

class Complex{

    int real;
    int img;

    public:

    Complex(int x ,int y){

         real=x;
        img=y;
    }

    void show(){
        cout<<real<<" + "<< img<<"i \n";
    }

    //operator overloading

    void operator +(Complex &c2){   //for addition
        int resReal=this->real +c2.real;
        int resImg=this->img +c2.img;

        Complex c3(resReal,resImg);
        cout<<"res = ";
        c3.show();
    }

    void operator -(Complex &c2){  //for substraction
        int resReal=this->real -c2.real;
        int resImg=this->img -c2.img;

        Complex c4(resReal,resImg);
        cout<<"res = ";
        c4.show();
    }
};

int main(){
    Complex c1(2,4);
    Complex c2(3,6);

    c1.show();
    c2.show();
    c1+c2;
    c1-c2;
    return 0;

}