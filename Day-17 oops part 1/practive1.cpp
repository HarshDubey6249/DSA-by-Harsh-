#include<iostream>
using namespace std;

class User{
    private:
        int id;
        string password;

    public:
    // constuctor
        User(int idVal)
        {
            cout<<"it is ini with constructor"<<endl;
            id= idVal;
        }
    //------------------------------------
        string username;
    //-------------------------------------
    //getter and setter for password
     void setPassword(string passwordval)
        {
            password= passwordval;
        }

       string getPassword()
        {
            return password;
        }
    //----------------------------------------------

    //get for constuctor

        int getIdval(){
            return id;
        }



};

int main(){
    User u1(234);

    u1.username="harsh";
    u1.setPassword("45434");

    cout<<"username . ."<<u1.username<<endl;
    cout<<"_id . ."<<u1.getIdval()<<endl;
    cout<<"password . ."<<u1.getPassword();
 return 0;
}