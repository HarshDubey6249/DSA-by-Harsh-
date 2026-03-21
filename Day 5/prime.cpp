#include <iostream>
using namespace std;

int main() {
    cout << "Prime numbers between 1 and 100 are: ";

    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}
