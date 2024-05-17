#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
          swap(arr[j],arr[j+1]);     
        }
    }
  }
}
void selection_sort(int *arr,int n){
   int min;

   for(int i=0;i<n-1;i++){
    min=i;

    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    swap(arr[min],arr[i]);
   }
}

void insertion_sort(int *arr,int n){
   int key,j;

   for(int i=1;i<n-1;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
   }
}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[]={8,9,11,2,3};
    int n=sizeof(arr)/sizeof(int);
   printArray(arr,n);
   return 0;
}