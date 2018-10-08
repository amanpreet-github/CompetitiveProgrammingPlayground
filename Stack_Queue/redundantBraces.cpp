

#include<bits/stdc++.h>

using namespace std;

int main() {
    string A("(a+(a+b))");
    stack<char> st;
    int redundant = 0;
    int i = 0;
    while (i < A.size()) {

        while (A[i] != ')' && i < A.size()) {
            st.push(A[i]);
            i++;
        }
        if (i == A.size()) return 0;
        char leftOperand = '\0', rightOperand = '\0', arithOperator = '\0';

        if (A[i] == ')') {
            while (st.top() != '(') {
                if (st.top() != '*' && st.top() != '+' && st.top() != '-' && st.top() != '/') {
                    if (rightOperand == '\0') rightOperand = st.top();
                    else if (leftOperand == '\0') leftOperand = st.top();
                } else {
                    arithOperator = st.top();
                }
                st.pop();
            }
            st.pop();
            if (leftOperand == '\0' || rightOperand == '\0' || arithOperator == '\0') return 1;
            leftOperand = '\0';
            rightOperand = '\0';
            arithOperator = '\0';
            st.push('a');
        }
        i++;

    }
}