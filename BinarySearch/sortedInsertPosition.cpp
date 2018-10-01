/*
 *
 *
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
 *
 *
 * */
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &Array, int start, int end, int searchElement) {

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (Array[mid] == searchElement)
            return mid;
        if (Array[mid] < searchElement) {
            start = mid + 1;
        } else end = mid - 1;
    }
    if (end == -1) {
        return 0;
    }
    return start;
}


int search(vector<int> &Array, int searchElement) {

    return binarySearch(Array, 0, (Array.size() - 1), searchElement);
}

int main() {

    vector<int> Array(5)
    int value, searchElement;
    cin >> searchElement;
    for (int i = 0; i < 5; i++) {
        cin >> value;
        Array[i] = value;
    }

    cout << search(Array, searchElement);

}