/*
 Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    stack <string> st;
    string A;
    string s;
    cin >> A;
    string res;
    res.append("/");
    for (int i = 0; i < A.size(); i++) {

        s.clear();

        while (i < A.size() && A[i] == '/') {
            i++;
        }

        while (i < A.size() && A[i] != '/') {
            s.push_back(A[i]);
            i++;
        }

        if (s.compare("..") == 0) {
            if (!st.empty()) {
                st.pop();
            }
        } else if (s.compare(".") == 0) {
            continue;
        } else if (s.length()) {
            st.push(s);
        }
    }

    stack <string> st1;
    while (!st.empty()) {
        st1.push(st.top());
        st.pop();
    }
    while (!st1.empty()) {
        string temp = st1.top();
        if (st1.size() != 1) {
            res.append(temp + '/');
        } else res.append(temp);
        st1.pop();
    }
    cout << res;

    return 0;
}