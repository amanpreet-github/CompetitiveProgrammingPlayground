/*
 Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that
    j is maximum possible AND
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

 * */

#include<bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(vector<int> A) {
    stack<int> s1;
    vector<int> Array(A.size());
    for (int i = 0; i < A.size(); i++) {
        if (s1.empty()) {
            Array[i] = -1;
            s1.push(A[i]);
        } else if (s1.top() < A[i]) {
            Array[i] = s1.top();
            s1.push(A[i]);
        } else {
            while (!s1.empty() && s1.top() >= A[i]) {
                s1.pop();
            }
            if (s1.empty()) {
                Array[i] = -1;
                s1.push(A[i]);
            } else {
                Array[i] = s1.top();
                s1.push(A[i]);
            }

        }

    }
    return Array;
}

int main() {
    int noOfElements, elementValue;
    cin >> noOfElements;
    vector<int> A(noOfElements);
    for (int i = 0; i < noOfElements; i++) {
        cin >> elementValue;
        A[i] = elementValue;
    }
    vector<int> array = prevSmaller(A);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " | ";
    }
    return 0;
}