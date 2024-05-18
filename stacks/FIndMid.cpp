#include <bits/stdc++.h>
using namespace std;

int helper(int i,stack<int>&st,int n)
{
    if(i==n/2)
    {
       return st.top();
    }
    
    int x=st.top();
    st.pop();
    
    int a=helper(i+1,st,n);
    st.push(x);
    return a;
}

int Delmin(stack<int>&st)
{
    int n=st.size();
    return helper(0,st,n);
}

int main() {
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    cout<<Delmin(st);
    
    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    return 0;
}