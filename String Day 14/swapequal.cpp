#include <iostream>
#include <vector>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    // 1. If both are already equal, no swap needed
    if (s1 == s2) return true;

    // 2. Store indices where s1 and s2 differ
    vector<int> diff;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diff.push_back(i);
        }
    }

    // 3. If mismatches are not exactly 2, not possible
    if (diff.size() != 4) return false;

    // 4. Try swapping those two indices in s1
    swap(s1[diff[0]], s1[diff[1]]);

    // 5. Now check if equal to s2
    return (s1 == s2);
}

int main() {
    string s1 = "baxnk";
    string s2 = "kxanb";

    cout << (areAlmostEqual(s1, s2) ? "true" : "false");
}
