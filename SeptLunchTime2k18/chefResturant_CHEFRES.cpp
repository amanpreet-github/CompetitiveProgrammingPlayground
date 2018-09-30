/*
 * Chef is a cook and he has recently opened a restaurant.

The restaurant is open during N time intervals [L1,R1),[L2,R2),…,[LN,RN).
 No two of these intervals overlap — formally, for each valid i, j such that i≠j, either Ri<Lj or Rj<Li.

M people (numbered 1 through M) are planning to eat at the restaurant; let's denote the time
 when the i-th person arrives by Pi. If the restaurant is open at that time, this person does not
 have to wait, but if it is closed, this person will wait until it is open. Note that if this person
 arrives at an exact time when the restaurant is closing, they have to wait for the next opening time.

For each person, calculate how long they have to wait (possibly 0 time), or determine that they will wait
 forever for the restaurant to open.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description
 of T test cases follows.
The first line of the input contains two space-separated integers N and M.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Li and Ri.
M lines follow. For each valid i, the i-th of these lines contains a single integer Pi.
Output
For each test case, print M lines. For each valid i, the i-th of these lines should contain
 a single integer — the time person i has to wait, or −1 if person i has to wait forever.

Constraints
1≤T≤100
1≤N,M≤105
1≤Li<Ri≤109 for each valid i
1≤Pi≤109 for each valid i
the intervals are pairwise disjoint
the sum of N for all test cases does not exceed 3⋅105
the sum of M for all test cases does not exceed 3⋅105
Subtasks
Subtask #1 (30 points):

the sum of N for all test cases does not exceed 1,000
the sum of M for all test cases does not exceed 1,000
Subtask #2 (70 points): original constraints

Example Input
1
4 5
5 7
9 10
2 3
20 30
3
0
7
40
2
Example Output
0
0
2
-1
1
 *
 *
 * */

#include<bits/stdc++.h>

using namespace std;

long int binarySearch(vector <vector<long int>> &twoDimArray, long int start, long int end, long int m, long int n,
                      long int searchElement) {


    while (start <= end) {
        int mid = start + (end - start) / 2;
        int row = (mid) / n;
        int col = (mid) % n;
        if (twoDimArray[row][col] == searchElement) {
            if (col == 1) {
                if (row == (m - 1)) {
                    return -1;
                } else {
                    return twoDimArray[row + 1][0] - searchElement;
                }

            }
            return 0;
        }
        if (twoDimArray[row][col] < searchElement) start = mid + 1;
        else end = mid - 1;
    }
    if (end == -1) {
        return twoDimArray[0][0] - searchElement;
    }
    if (start == m * 2) {
        return -1;
    }
    int mid = end + abs((start - end)) / 2;
    int row = (mid) / n;
    if (twoDimArray[row][0] < searchElement && searchElement < twoDimArray[row][1]) {
        return 0;
    }
    return twoDimArray[row + 1][0] - searchElement;


}

bool sortByColumn(const vector<long int> &v1, const vector<long int> &v2) {
    return v1[0] < v2[0];
}

int main() {
    int t, nIntervals, mPersons;
    cin >> t;
    while (t--) {
        cin >> nIntervals >> mPersons;
        long int intervalValue = 0, personValue = 0;
        vector <vector<long int>> resturantOpenInterval(nIntervals);
        vector<long int> person(mPersons);

        // input resturants open intevals
        for (int i = 0; i < nIntervals; i++) {
            resturantOpenInterval[i] = vector<long int>(2);
            for (int j = 0; j < 2; j++) {
                cin >> intervalValue;
                resturantOpenInterval[i][j] = intervalValue;
            }
        }

        // sort the resturants open interval in ascending order on the basic of column
        sort(resturantOpenInterval.begin(), resturantOpenInterval.end(), sortByColumn);


        // input persons arriving time
        for (int i = 0; i < mPersons; i++) {
            cin >> personValue;
            person[i] = personValue;
            //fetch row index
        }
        for (int i = 0; i < mPersons; i++) {
            cout << binarySearch(resturantOpenInterval, 0, nIntervals * 2 - 1, nIntervals, 2, person[i]) << endl;
        }


    }

}
