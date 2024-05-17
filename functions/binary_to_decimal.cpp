#include<iostream>
using namespace std;

int b_to_d(int n){
    int ans=0;
    int p=1;
   
   while(n!=0){
    int ld=n%10;
    ans=ans+(ld*p);
    p=p*2;
    n=n/10;
   }
   return ans;
}

int main(){
    cout<<b_to_d(1010);
    return 0;
}