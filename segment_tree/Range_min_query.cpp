// Online C++ compiler to run C++ program online
#include <bits/stdc++.h> 
using namespace std; 

void update(int index, int val, int n,int feed[],int arr[]) 
{
    int size=ceil(sqrt(n));
    int ptr=index/size;
    feed[ptr] = min(val,feed[ptr]);
    arr[index]=val;
}

int query(int l,int r,int n,int feed[],int arr[])
{
    int ans = INT_MAX;
    int size = ceil(sqrt(n));
    
    while(l<r && l%size!=0 && l!=0)
    {
        if(arr[l]<ans){
            ans=arr[l];
        }
        l++;
    }
    
    while(l+size<r)
    {
        if(feed[l/size]<ans)
        {
            ans=feed[l/size];
        }
        l+=size;
    }
    
    while(l<=r)
    {
        if(arr[l]<ans)
        ans=arr[l];
        l++;
    }
    return ans;
}

void Build(int input[],int n,int arr[],int feed[])
{
    int ptr=-1;
    
    int size=ceil(sqrt(n));
    for(int i=0;i<n;i++)
    {
        arr[i]=input[i];
        if(i%size==0)
        {
            ptr++;
            feed[ptr] = arr[i];
        }else{
            feed[ptr] = min(feed[ptr],arr[i]);
        }
    }
}

int main() {
    // Write C++ code here
    int input[] = {8, 5, 12, 4, 6, 1, 14 , 7, 7, 10}; 
    int n = sizeof(input)/sizeof(input[0]); 
    int arr[n],feed[n];
    Build(input, n, arr,feed); 
    cout << "query(7,9) : Before update" <<"\t"<< query(7, 9,n,feed,arr) << endl; 
    update(8, 0,n,feed,arr); //update 8 index by 0
    cout << "query(7,9) : After update" <<"\t"<< query(7, 9,n,feed,arr) << endl; 
    return 0; 

    return 0;
}