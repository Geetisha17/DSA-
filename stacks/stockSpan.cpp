#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpanner(vector<int> &stocks)
{
    vector<int>span;

    span[0]=1;
    stack<int>s;
    s.push(0);
    int n=stocks.size();

    for(int i=0;i<n;i++)
    {
        int curr=stocks[i];
        while(!s.empty() && stocks[s.top()]<=curr){
            s.pop();
        }

        if(!s.empty()){
            span[i] = i-s.top();
        }else{
            span[i] = i+1;
        }

        s.push(i);
    }
    return span;
}