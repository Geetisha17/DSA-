#include<iostream>
using namespace std;

void rev(int *arr,int n){

    for(int i=0;i<n/2;i++){
        int first = arr[i];
        int last = arr[n-i-1];
        arr[i] = last;
        arr[n-i-1] = first;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void rev_two(int *arr,int n){
    int s=0;
    int e=n-1;

    while(s<e){
       swap(arr[s++],arr[e--]);
    }
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}

int main(){
//   int arr[]={1,2,3,4,5,6};
//   int n=sizeof(arr)/sizeof(n);
//    rev(arr,n);

   int T;
   cin>>T;

   while(T>0){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    T--;
   }
    return 0;
}