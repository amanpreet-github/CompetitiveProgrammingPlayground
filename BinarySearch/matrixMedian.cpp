/*
 *
 * Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. Assume N*M is odd.

For example,

Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.
 *
 *
 * */

#include<bits/stdc++.h>

using namespace std;

int binaryMedian(vector <vector<int>> &m, int r, int c) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++) {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];

        // Finding the maximum element
        if (m[i][c - 1] > max)
            max = m[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}


int main() {

    int rows, cols, value;
    cin >> rows >> cols;
    vector <vector<int>> twoDArray(rows);
    for (int i = 0; i < rows; i++) {
        twoDArray[i] = vector<int>(cols);
        for (int j = 0; j < cols; j++) {
            cin >> value;
            twoDArray[i][j] = value;
        }
    }

    cout << binaryMedian(twoDArray, rows, cols);
}