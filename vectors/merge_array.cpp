#include<bits/stdc++.h>
using namespace std;

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=m-1,j=n-1,k=m+n-1;

      while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            k--;
            i--;
        }
        else{
            nums1[k]=nums2[j];
            k--;
            j--;
        }
      }
      while(i>=0){
        nums1[k]=nums1[i];
            k--;
            i--;
      }
      while(j>=0){
         nums1[k]=nums2[j];
            k--;
            j--;
      }
}



int main(){
   vector<int> nums1={2,4,6};
   vector<int> nums2={1,3,9};
   int m=3,n=3;
   nums1.resize(m+n);
   merge(nums1,m,nums2,n);
   for(int &x:nums1){
    cout<<x<<" ";
   }
    return 0;
}