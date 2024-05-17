#include<bits/stdc++.h>
using namespace std;

int elementPresentOrNot(vector<int> array, int element) {
    
    for(int i=0;i<array.size();i++){
        if(array[i]==element){
            return 1;
            break;
        }
        else{
            return 0;
        }
    }
}

void frequency(int *arr, int n){
    int max=arr[0];
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
            count++;
        }
    }
    cout<<max<<endl;
    cout<<count;
   
}

int main(){
    int arr[]={1,2,3,4,4,4,4,4,4};
    int n=sizeof(arr)/sizeof(int);
    frequency(arr,n);
    return 0;
}