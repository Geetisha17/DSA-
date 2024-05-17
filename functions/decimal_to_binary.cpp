#include<iostream>
using namespace std;

int d_to_b(int n){
    int ans=0;
    int p=1;

    while(n!=0){
        int ld=n%2;
        ans=ans+(ld*p);
        p=p*10;
        n=n/2;
    }
    return ans;
}

int main(){
    cout<<d_to_b(10);
    return 0;
}