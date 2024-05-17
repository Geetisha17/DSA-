#include<bits/stdc++.h>
using  namespace std;


/*
   0 1 2 3 4 5 
0 |1                
1 |1 1
2 |1 2 1
3 |1 3 3 1
4 |1 4 6 4 1
5 |1 5 10 10 5 1
*/

vector<vector<int>> printPascal(int n)
{
    // your code goes here
     vector<vector<int>> ans;
   
   for(int i=0;i<n;i++){
       vector<int> v;
       
       for(int j=0;j<=i;j++){            // no. of cols=no. of rows.             
           if(i==j || j==0){        // i=row j=col if row==col then it is 1 and 0th col is always 1.
               v.push_back(1);
           }
           else{
               v.push_back(ans[i-1][j-1]+ans[i-1][j]);
           }
       }
       ans.push_back(v);
   }
   return ans;
    
}

int main(){
    cout<<"hey";
    return 0;
}