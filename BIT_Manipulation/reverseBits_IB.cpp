/*
 * Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011
=>        11000000000000000000000000000000
return 3221225472


 *
 * */


#include <bits/stdc++.h>
using namespace std;

// entry point
int main() {

    unsigned long decimal;

    cin >> decimal;

    string str;

    // get the binary string
    str = bitset<32>(decimal).to_string();

    // reversing the binary string
    reverse(str.begin(), str.end());

    unsigned long reverseDecimal;

    // getting the decimal value
    reverseDecimal = bitset<32>(str).to_ulong();

    cout << reverseDecimal << endl;

}

// note: bitset library is used t covert the decimal value to a binary string and the binary string to a decimal value.