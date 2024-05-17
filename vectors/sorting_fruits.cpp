#include<bits/stdc++.h>
using namespace std;

bool check(pair<string,int> marks, pair<string,int> mar){
  return marks.second<mar.second;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    // your code  goes here
    if(S=="name"){
        sort(v.begin(),v.end());
    }
    else if(S=="price"){
        sort(v.begin(),v.end(),check);
    }

    return v;
}