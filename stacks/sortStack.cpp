#include <bits/stdc++.h>
using namespace std;

void helper(stack<int>& st, int num) {
    if (st.empty() || st.top() > num) {
        st.push(num);
        return;
    } else {
        int x = st.top();
        st.pop();
        helper(st, num);
        st.push(x);
    }
}

void Delmin(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int x = st.top();
    st.pop();
    Delmin(st);
    helper(st, x);
}

int main() {
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    
    Delmin(st);
    
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
