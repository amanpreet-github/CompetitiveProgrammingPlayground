/*
 *
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
 * */

#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, n, d;
    cin >> x >> n >> d;
    long long a = x % d;
    long long t = 1;
    while (n > 0) {
        if (n & 1) {
            t = ((t % d) * (a % d)) % d;
        }
        n >>= 1;
        cout << "t is" << t << endl;
        a = ((a % d) * (a % d)) % d;
    }
    if (n == 0 && x == 0) {
        cout << 0;
    }
    if (n == 0) {
        cout << x % d;
    }
    if (t < 0) {
        cout << "t " << d << t << endl;
        cout << (d + t);
    }
    cout << t;
}