/*
 There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5
 * */
#include<bits/stdc++.h>

using namespace std;

double binarySearch(vector<int> &A, vector<int> &B) {
    int start = 0;
    int end = A.size();
    int total = A.size() + B.size();
    while (start <= end) {
        int positionX = start + (end - start) / 2;
        int positionY = (A.size() + B.size() + 1) / 2 - positionX;
        cout << "x --" << positionX << "y ---" << positionY << endl;
        int left_x_Max = ((positionX - 1) < 0 ? INT_MIN : A[positionX - 1]);
        int right_x_Min = (positionX == A.size()) ? INT_MAX : A[positionX];
        int left_y_Max = (positionY - 1) < 0 ? INT_MIN : B[positionY - 1];
        int right_y_Min = (positionY == B.size()) ? INT_MAX : B[positionY];
        if (left_x_Max <= right_y_Min && left_y_Max <= right_x_Min) {
            if (total & 1) return max(left_x_Max, left_y_Max);
            return (double) (max(left_x_Max, left_y_Max) + min(right_x_Min, right_y_Min)) / 2;
        }
        if (left_x_Max > right_y_Min) {
            end = positionX - 1;
        } else start = positionX + 1;
    }
    return -1;
}


double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    if (A.size() <= B.size()) return binarySearch(A, B);
    return binarySearch(B, A);
}

int main() {
    int noOfAelements, noOfBelements, elementA, elementB;
    cin >> noOfAelements >> noOfBelements;
    vector<int> ArrayA(noOfAelements), ArrayB(noOfBelements);
    for (int i = 0; i < noOfAelements; i++) {
        cin >> elementA;
        ArrayA[i] = elementA;
    }
    for (int i = 0; i < noOfBelements; i++) {
        cin >> elementB;
        ArrayB[i] = elementB;
    }


    cout << findMedianSortedArrays(ArrayA, ArrayB);
}