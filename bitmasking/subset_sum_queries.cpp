#include<bits/stdc++.h>
using namespace std;

vector<bool> subsetSum(vector<int> v, vector<int> q)
{
    int n=v.size();
    vector<bool> b;

    bitset<10000> bit;
    bit.reset();
    bit[0]=1;

    for(int i=0;i<v.size();i++){
        bit |=(bit<<v[i]);
    }

    for(int i=0;i<n;i++){
        bit[q[i]]? b[i]=true:b[i]=false;
    }
    return b;
}