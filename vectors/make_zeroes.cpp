#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    // your code goes here
     int col=1;
     int rows = arr.size();
     int cols = arr[0].size();
     
     for(int i=0;i<rows;i++){
         
        if(arr[i][0]==0) col=0;
         
         for(int j=0;j<cols;j++){
             if(arr[i][j]==0){
                 arr[0][j] = arr[i][0] =0;
             }
         }
     }
     
     for(int i=rows-1; i >=0;i--){
         for(int j=cols-1;j>=0;j--){
             
             if(arr[i][0]==0 || arr[0][j]==0)
                 arr[i][j]=0;
             if(col==0) arr[i][0]=0;
         }
     }
     return arr;
}

int main(){
    vector<vector<int>> arr={ {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} };
    vector<vector<int>> x=makeZeroes(arr);

   for(int  i=0;i<arr.size();i++){
    for(int j=0;j<x[i].size();j++){
         cout<<x[i][j]<<" ";
          }
          cout<<endl;
    }
    return 0;
}