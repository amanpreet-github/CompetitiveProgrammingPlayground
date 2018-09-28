/*
 *
 *
 *   Write a function that takes an unsigned integer and returns the number of 1 bits it has.

     Example:

    The 32-bit integer 11 has binary representation

    00000000000000000000000000001011
    so the function should return 3.
 *
 *
 *
 *
 * */

#include <bits/stdc++.h>

using namespace std;

// entry point
int main() {
    unsigned long decimal;
    cin >> decimal;
    string str;
    int count = 0;
    str = bitset<32>(decimal).to_string();
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == '1') count++;
    }
    cout << count << endl;

}