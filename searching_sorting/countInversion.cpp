// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
// int cnt=0;
int merge(vector<int>&nums,int s,int e){
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;
    vector<int>ans;
    int cnt=0;
    while(i<=mid && j<=e){
        if(nums[i]<nums[j]){
            ans.push_back(nums[i++]);
        }else{//right is smaller
        cnt+=(mid-i+1);
            ans.push_back(nums[j++]);
        }
    }
    
    while(i<=mid){
        ans.push_back(nums[i++]);
    }
    while(j<=e){
        ans.push_back(nums[j++]);
    }
    
    int k=0;
    
    for(int i=s;i<=e;i++){
        nums[i]=ans[k++];
    }
    return cnt;
}

int mergesort(vector<int>&array,int s,int e)
{
    int cnt=0;
   if(s>=e){
        return cnt;
    }
    int mid=(s+e)/2;
    cnt+=mergesort(array,s,mid);
    cnt+=mergesort(array,mid+1,e);
    cnt+=merge(array,s,e);
    
    return cnt;
}
int countInversion(vector<int>&nums,int n){
    return mergesort(nums,0,n-1);
}

int main() {
    vector<int>nums={5,3,2,4,1};
    cout<<countInversion(nums,5);
    return 0;
}