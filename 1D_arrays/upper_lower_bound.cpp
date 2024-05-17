#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> A, int val){
    int low = INT_MIN;
    int n = A.size();
    for(int i=0;i<n;i++){
        low = (A[i] > low && A[i] <= val) ? A[i] : low;
    }

    if(low==INT_MIN){
        return -1;
    }
    else{
        return low;
    }
}

int upper_bound(vector<int> A, int val){
    int high=INT_MIN;
    int n = A.size();

    for(int i=0;i<n;i++){
        if(high<A[i] && A[i]>val){
            high=A[i];
            break;
        }
    }
    if(high==INT_MIN){
        return -1;
    }
    return high;
}

int main(){
    vector<int> A={-1,-1,2,3,5,9,10};
    int val;
    cout<<"enter a value";
    cin>>val;
    cout<< upper_bound(A,val);
    
    return 0;
}