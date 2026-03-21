#include<iostream>
#include<string>
using namespace std;

void odd(string s){
    string ans = "";

    for(int i = s.size() - 1; i >= 0; i--) {

        // Check if digit is odd
        if((s[i] - '0') % 2 == 1) {
            ans = s.substr(0, i + 1);
            break;
        }
    }

    cout << ans;
}

int main(){
    string num = "52";
    odd(num);
    return 0;
}
