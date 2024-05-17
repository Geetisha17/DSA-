#include<iostream>
#include<algorithm>
using namespace std;

int missing_no(int *arr,int n){
     int sum=0;
     int total = ((n+1)*(n+2))/2;
     for(int i=0;i<n;i++){
        sum=sum+arr[i];
     }
     return total-sum;
}

int kth(int *arr,int n,int k){

    sort(arr,arr+n);
    return arr[k-1];
}

int median(int *arr,int n){
    int x=n/2;
    if(n%2!=0)
    return arr[x];
    return (arr[x-1]+arr[x])/2;
}

int largest(int *arr,int n){
    int max=arr[0];

    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<median(arr,n);
    return 0;
}