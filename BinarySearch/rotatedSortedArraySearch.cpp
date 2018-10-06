/*
 *
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates.
 Does your current solution work? How does the time complexity change?*
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &array, int start, int end, int searchElement) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == searchElement) return mid;
        if (array[mid] > searchElement) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}


vector<int> minElement(vector<int> &array, int start, int end) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (array[mid] > array[end]) start = mid + 1;
        else end = mid;
    }
    vector<int> element(2);
    if (start == end) {
        element[0] = array[start];
        element[1] = start;
        return element;
    }

}

int search(vector<int> &array, int searchElement) {
    vector<int> pivotElement(2);
    pivotElement = minElement(array, 0, array.size() - 1);
    int pivotLeft = binarySearch(array, 0, pivotElement[1] - 1, searchElement);
    int pivotRight = binarySearch(array, pivotElement[1], array.size() - 1, searchElement);
    if (pivotLeft != -1) return pivotLeft;
    if (pivotRight != -1) return pivotRight;
    return -1;
}

int main() {
    int arrayLength, arrayElement, searchElement;
    cin >> arrayLength >> searchElement;
    vector<int>
            array(arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        cin >> arrayElement;
        array[i] = arrayElement;
    }
    cout << search(array, searchElement) << endl;
    return 0;
}