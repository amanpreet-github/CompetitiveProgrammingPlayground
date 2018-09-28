/*
 *
We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,…, AN.
 Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N.
 Return the answer modulo 109+7.

For example,

A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8
 *
 *
 * */


#include <bits/stdc++.h>

long long int MOD = 1e9 + 7;
using namespace std;

int main() {
    long long int n;

    cin >> n;

    long long int A[n];

    for (long long int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int total = 0;

    vector<int> map_0(32, 0);
    vector<int> map_1(32, 0);


    for (int i = 0; i < n; i++) {
        int count = 0;
        // converting decimal value to a binary string using bitset library
        string str = bitset<32>(A[i]).to_string();

        // storing each position 1's bit in map_1 and 0's bit in map_0
        for (string::iterator it = str.begin(); it != str.end(); ++it) {
            if (*it == '1') map_1[it - str.begin()]++;
            else map_0[it - str.begin()]++;
        }
    }

    for (int i = 0; i < 32; i++) {
        int mult = (map_0[i] % MOD * map_1[i] % MOD) % MOD;
        total = (total % MOD + mult % MOD) % MOD;
        total = total % MOD;
    }

    cout << (2 % MOD * total % MOD) % MOD << endl;

}