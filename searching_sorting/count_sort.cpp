#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void count_sort(int arr[],int n){
   int largest = INT_MIN;
 // finding the largest element in an array.
    for(int i=0;i<n;i++){
        largest = max(largest,arr[i]);
    }
// creating a new dynmaic array to store the values
    vector<int> freq(largest+1,0);
   // storing the value at the next index every time the loop iterates 
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
// putting the values back in the array.
    int j=0; // the orignal array
    for(int i=0;i<=largest;i++){
        while(freq[i]>0){   // the dynamic array created must be greater than zero so as to store the value of nos given in the original  array.
            arr[j]=i; // putting the value at i in the original array at jth index.
            freq[i]--;  // decreasing the value of the paticular no. in dynamic array.
            j++; // moving the j to the next index in the original array to place the values back in correct order.
        }
    }
}
