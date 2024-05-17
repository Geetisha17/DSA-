
#include <bits/stdc++.h> 
using namespace std;

int unboundedKnapsack(int n, int maxweight, vector<int>& val, vector<int>& weight) {
    vector<vector<int>> dp(n, vector<int>(maxweight + 1, 0));

    for (int i = 0; i <= maxweight; i++) {
        dp[0][i] = i / weight[0] * val[0];
    }

    for (int idx = 1; idx < n; idx++) {
        for (int w = 0; w <= maxweight; w++) {
            int noTake = dp[idx - 1][w];
            int take = 0;

            if (weight[idx] <= w) {
                take = val[idx] + dp[idx][w - weight[idx]];
            }

            dp[idx][w] = max(noTake, take); // Update dp table with the maximum value
        }
    }

    return dp[n - 1][maxweight];
}

// int helper(int idx,int w,vector<int>val,vector<int>weight,vector<vector<int>>&dp)
// {
//     if(idx==0)
//     {
//         if(weight[0]<=w) return (w/weight[0])*val[0];
//         else return 0;
//     }

//     if(dp[idx][w]!=-1) return dp[idx][w];

//     int noTake= helper(idx-1,w,val,weight,dp);
//     int take=0;

//     if(weight[idx]<=w)
//     {
//         take = val[idx] + helper(idx,w-weight[idx],val,weight,dp);
//     }

//     return dp[idx][w] = max(take,noTake);
// }


// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     // Write Your Code Here.
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     return helper(n-1,w,profit,weight,dp);
// }