/*
 *
 Given an array of N integers, find the pair of integers in the array which have minimum XOR value.
 Report the minimum XOR value.

Examples :
Input
0 2 5 7
Output
2 (0 XOR 2)
Input
0 4 7 9
Output
3 (4 XOR 7)

Constraints:
2 <= N <= 100 000
0 <= A[i] <= 1 000 000 000
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int minXorValue(vector<long int> &A) {
    sort(A.begin(), A.end());
    long long int minVal = INT_MAX;
    long long val = A[0];
    for (long i = 1; i < A.size(); i++) {
        minVal = min(minVal, val ^ A[i]);
        val = A[i];
    }
    return minVal;
}

int main() {
    vector<long int> Array(5);
    for (int i = 0; i < 5; i++) {
        cin >> Array[i];
    }
    cout << minXorValue(Array);
}