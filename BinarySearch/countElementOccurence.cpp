/*
 *
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
 *
 * */
#include<bits/stdc++.h>

using namespace std;

int rangeStart(vector<int> &A, int start, int end, int B) {
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (A[mid] >= B) {
            end = mid;
        }
        if (A[mid] < B) {
            start = mid + 1;
        }
    }
    if (A[start] == B) return start;
    return -1;
}

int rangeEnd(vector<int> &A, int start, int end, int B) {
    while (start < end) {
        int mid = start + (end - start) / 2 + 1;

        if (A[mid] <= B) {
            start = mid;
        }
        if (A[mid] > B) {
            end = mid - 1;
        }
    }
    if (A[start] == B) return start;
    return -1;
}


int main() {

    vector<int> Array(5);

    int searchElement;

    cin >> searchElement;
    for (int i = 0; i < 5; i++) cin >> Array[i];
    int startPoint = rangeStart(Array, 0, Array.size() - 1, searchElement);
    int endPoint = rangeEnd(Array, 0, Array.size() - 1, searchElement);
    if (endPoint == -1 || startPoint == -1) return 0;
    cout << endPoint - startPoint + 1 << endl;
}