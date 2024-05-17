#include<iostream>
using namespace std;

int sieve(int n){
    if(n<=1){
        return 0;
    }
    bool isprime[n];
    
    for(int i=2;i<n;i++){
        isprime[i]=true;
    }
    for(int i=2;i*i<n;i++){
        
        if(!isprime[i]) continue;
        for(int j=i*i;j<n;j+=i){
            isprime[j] = false;
        }
    }
    
    int count=0;
    for(int i=2;i<n;i++){
        if(isprime[i]){
        count++;}
    }
    return count;
}
// int countPrimes(int n)
// {
//     if(n < 3)
//         return 0;
//     return sieve(n);
// }

int main(){

   cout<<sieve(10);
    return 0;
}