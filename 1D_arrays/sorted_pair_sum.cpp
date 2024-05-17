#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
  int n=arr.size();
   int l=0;
   int r=n-1;
   int res_l=0,res_r=0,diff=INT_MAX;

   while(l<=r){

       if( abs(arr[l]+arr[r]-x) < diff){
           res_l=arr[l];
           res_r=arr[r];
           diff= abs(arr[l]+arr[r]-x);
           
       }
       if (arr[l]+arr[r]>x){
           r--;
       }
       else{
           l++;
       }
   }
   return {res_l,res_r};
}

int main(){
     vector<int> length={10,22,28,29,30,40};
    int D=50;

    pair<int,int> coords=closestSum(length,D);
    cout<<coords.first<<" "<<coords.second<<" ";
    return 0;
}
//{10, 22, 28, 29, 30, 40}, x = 54
//ans=22 and 30


