#include<bits/stdc++.h>
using namespace std;

int linear_search(int *arr,int n,int key){
    for(int i=0;i<=n;i++){
        if(arr[i]==key)
        return 1;
        
    }
    return 0;
}

int binary_search(int *arr,int n,int key){

    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        
    }
    return -1;
}
int main(){
    int arr[]={1,2,4,78,90};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    sort(arr,arr+n);
    cout<<binary_search(arr,n,key);
    
    return 0;
}