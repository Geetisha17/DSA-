#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long int n;
    cout<<"enter the no. of elements ";
    cin>>n;
   int t;
   cin>>t;
    while(t--){
    long long int i,arr[n];

    for(i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    for(i=0;i<n && arr[i]==1;i++){
         cout<<arr[i]<<" ";
    }

    if(i==n-2 && arr[i]==2 &&arr[i+1]==3){
        cout<<arr[i]<<" "<<arr[i+1];
    }
    else {
        for(i=n-1;i>=0 && arr[i]!=1;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
  }   

 return 0;
}