/*
 *
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
 *
 *
 * */
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector <vector<int>> &twoDimArray, int start, int end, int m, int n, int searchElement) {

    if (start > end) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int row = (mid) / n;
    int col = (mid) % n;
    if (twoDimArray[row][col] == searchElement)
        return 1;
    if (twoDimArray[row][col] < searchElement) {
        return binarySearch(twoDimArray, mid + 1, end, m, n, searchElement);
    }
    return binarySearch(twoDimArray, start, mid - 1, m, n, searchElement);
}


int searchMatrix(vector <vector<int>> &twoDimArray, int searchElement) {

    return binarySearch(twoDimArray, 0, (twoDimArray.size() * twoDimArray[0].size()) - 1, twoDimArray.size(),
                        twoDimArray[0].size(), searchElement);
}

int main() {


    vector<int> twoDimArray(m *n)
    int value, searchElement;
    cin >> searchElement;
    for (int i = 0; i < 10; i++) {
        twoDimArray[i] = vector<int>(7);
        for (int j = 0; j < 7; j++) {
            cin >> value;
            twoDimArray[i][j] = value;
        }
    }

    cout << searchMatrix(twoDimArray, searchElement);

}