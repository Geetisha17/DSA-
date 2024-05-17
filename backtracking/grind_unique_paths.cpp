#include<iostream>
#include<algorithm>
using namespace std;

int gridPath(int m,int n){
    int ans=1;
    int y=1;

    for(int i=max(m,n) ; i<=m+n-2;i++){
        ans= ans*i;
       while(y<= min(m,n) && ans%y==0){
        ans=ans/y;
        y++;
       }
    }
    return ans;
}

int main(){
    cout<<gridPath(3,7);
    return 0;
}