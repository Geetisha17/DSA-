#include<bits/stdc++.h>
using namespace std;


void reverse(vector<int> &a, int low, int high){

while(low<=high){
    swap(a[low],a[high]);
    low++;
    high--;
}
}

vector<int> kRotate(vector<int> a, int k){
    // your code  goes here
    int n = a.size();
    k = k%n;
    reverse(a, 0, n-k-1);
    reverse(a, n-k, n-1);
    reverse(a, 0, n-1);
    return a;
    
}