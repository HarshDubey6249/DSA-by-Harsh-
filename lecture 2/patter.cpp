#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {       // controls number of rows
        for (int j = 1; j <= i; j++) {   // prints stars in each row
            cout << "*";
        }
        cout << endl; // move to next line
    }
    return 0;
}
