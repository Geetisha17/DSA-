#include <iostream> 
#include <vector> 
using namespace std; 

int fun(vector<vector<int> > a, vector<vector<int> > t, 
        int cl, int cs, int x1, int x2, int n,vector<vector<int>>&dp) {
            
            if(cs==n-1)
            {
                if(cl==0) return dp[cs][cl]= x1;
                else return dp[cs][cl]= x2;
            }
            
            int same = fun(a,t,cl,cs+1,x1,x2,n,dp) + a[cl][cs+1];
            int diff = fun(a,t,!cl,cs+1,x1,x2,n,dp) + a[!cl][cs + 1] + t[cl][cs + 1];
            
            return dp[cs][cl]= min(same,diff);
        }

int main() {
    int n = 4;
    vector<vector<int> > a 
        = { { 4, 5, 3, 2 }, { 2, 10, 1, 4 } }; 
    vector<vector<int> > t 
        = { { 0, 7, 4, 5 }, { 0, 9, 2, 8 } }; 
        
        vector<vector<int>>dp(n,vector<int>(2,0));
  
    int e1 = 10; 
    int e2 = 12; 
    int x1 = 18; 
    int x2 = 7; 
    // entry from 1st line 
    int x = fun(a, t, 0, 0, x1, x2, n,dp) + e1 + a[0][0]; 
    // entry from 2nd line 
    int y = fun(a, t, 1, 0, x1, x2, n,dp) + e2 + a[1][0]; 
    cout << min(x, y) << endl;

    return 0;
}