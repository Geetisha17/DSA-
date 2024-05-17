#include<iostream>
#include<vector>
using namespace std;

// 10 5 2 0 7 6 4 
// 2 0 4 5 7 6 10  arranging elements less than pivot on left side and greater than on right side
// 0 2 4 5 6 7 10   finally arranging the elements on both the side in correct order

int merge(vector<int> &a,int s,int e){
    int pivot=a[e];  //we'll take a pivot element 4 and compare all the elements in an array
    int i=s-1;     
    
    for(int j=s;j<e;j++){  //we'll iterate throught the entire array 
        if(a[j]<pivot){  // we'll check if the element is smaller than pivot or not 
            i++;        //if yes we'll replace it with the first element in the array
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[e]);  // putting the  pivot element in the right place.
    return i+1;         
}

void quickSort(vector<int> &a,int s,int e){
    if(s>=e){
        return;
    }
    int p = merge(a,s,e);
    quickSort(a,0,p-1);
    quickSort(a,p+1,e);
}

int main(){
    vector<int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e=arr.size()-1;
    quickSort(arr,s,e);
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}