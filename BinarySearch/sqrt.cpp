/*
 *
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int binarySearch(long int number) {
    if (A == 0) return 0;
    int start = 1, end = A, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid <= A/ mid) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    long int number;

    cout << binarySearch(number);
}