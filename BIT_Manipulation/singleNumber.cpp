/*
 * Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3
 * */

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int singleNumber(vector<int> &A) {
    int value = 0;
    for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {
        value ^= *it;
    }
    return value;
}


int main() {
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    singleNumber(arr);
}