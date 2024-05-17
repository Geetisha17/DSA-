#include<iostream>
using namespace std;

int nCr(int n,int r){
    int ans=1;
    if(r<n){
        r=n-r;
    }
    for(int i=0;i<r;i++){
        ans=ans*(n-i);
        ans=ans/(i+1);
    }
    return ans;
}

int main(){
    cout<<nCr(8,3);
    return 0;
}