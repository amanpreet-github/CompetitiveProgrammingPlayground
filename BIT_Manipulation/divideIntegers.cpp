
/*
 *
 * Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
 *
 * */

#include <bits/stdc++.h>

using namespace std;

int divide(int x, int y) {
    long long temp = 0, quotient = 0;

    long long A = x, B = y;
    // check the signed bit ;
    long long sign = ((A < 0) ^ (B < 0)) ? -1 : 1;

    A = abs(A);
    B = abs(B);

    for (int i = 31; i >= 0; i--) {
        // fetching the value for a particular bit.
        if (temp + B << i <= A) {
            temp += B << i;
            quotient |= 1LL << i;
        }
    }
    if (sign < 0) quotient = -quotient;
    return quotient > INT_MAX || quotient < INT_MIN ? INT_MAX : quotient;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
}
