#include <bits/stdc++.h> 
using namespace std;

bool isOp(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    return true;
    return false;
}

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || isOp(ch)) {
            st.push(ch);
        } else if (ch == ')') {
            bool hasOperator = false; 
            while (!st.empty() && st.top() != '(') {
                if (isOp(st.top())) {
                    hasOperator = true;
                }
                st.pop();
            }
            st.pop(); 

            if (!hasOperator) {
                return true;
            }
        }
    }

    return false;
}
