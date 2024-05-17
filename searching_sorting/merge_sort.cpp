#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &array,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> temp;
    // 10,5,2,4,3,1
    //  i     j  i=10 and j=4 if a[i]>a[j] in temporary vector we'll push back a[j].
    while(i<=m && j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }else{
            temp.push_back(array[j]);
            j++;
        }
    }
    //copy remaining elements
    while(i<=m){
        temp.push_back(array[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(array[j]);
        j++;
    }
    int k=0;
    //copy back elements from temporary vector to original vector
    for(int idx=s ; idx<=e ; idx++ ){
        array[idx] = temp[k];
        k++;
    }
    return;
}

void mergesort(vector<int> &array,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    merge(array,s,e);
}


int main(){
    vector<int> arr{10,5,2,0,7,6,4};

    int s=0;
    int e=arr.size()-1;
    mergesort(arr,s,e);
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}