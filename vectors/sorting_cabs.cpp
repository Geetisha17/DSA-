#include<bits/stdc++.h>
using namespace std;

int totalSum(pair<int,int> &coords){
    return coords.first+coords.second;
}

bool comp(pair<int,int> &v1 , pair<int,int> &v2){
   
    return totalSum(v1) < totalSum(v2);
}

vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
    // your code  goes here
    sort(v.begin(),v.end(),comp);
    return v;
}