#include <bits/stdc++.h>
using namespace std;

void helper(int i,stack<int>&st,int n,int nums)
{
    if(i==n)
    {
       st.push(nums);
       return;
    }
    
    int x=st.top();
    st.pop();
    
    helper(i+1,st,n,nums);
    st.push(x);
}

void Delmin(stack<int>&st,int num)
{
    int n=st.size();
     helper(0,st,n,num);
}

int main() {
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    Delmin(st,10);
    
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}