/*
 *
 *
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &Array) {
    int secondTimeOccurence = 0, firstTimeOccurence = 0;
    for (vector<int>::iterator it = Array.begin(); it != Array.end(); ++it) {
        secondTimeOccurence = secondTimeOccurence | (firstTimeOccurence & *it);
        firstTimeOccurence = (firstTimeOccurence ^ *it);
        int neutral = ~(firstTimeOccurence & secondTimeOccurence);
        firstTimeOccurence = (firstTimeOccurence & neutral);
        secondTimeOccurence = (neutral & secondTimeOccurence);
    }
    return firstTimeOccurence;
}

int main() {

    vector<int> Array(5);
    for (int i = 0; i < 4; i++) {
        cin >> Array[i];
    }

    cout << singleNumber(Array);

}