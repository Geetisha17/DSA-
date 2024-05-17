#include <bits/stdc++.h> 
using namespace std;


int helper(int idx, int n, vector<int>& price, vector<vector<int>>& dp) {
    if (idx == 0)
        return n * price[0];

    if (dp[idx][n] != -1)
        return dp[idx][n];

    int notTake = helper(idx - 1, n, price, dp);
    int take = INT_MIN;

    int rodlength = idx + 1;
    if (rodlength <= n)
        take = price[idx] + helper(idx, n - rodlength, price, dp);

    return dp[idx][n] = max(take, notTake);
}

int cutRod(vector<int>& price, int n) {
 vector<vector<int>> dp(n, vector<int>(n + 1, -1));    
 return helper(n - 1, n, price, dp);
}

// int cutRod(vector<int>& price, int n) {
//     vector<vector<int>> dp(n, vector<int>(n + 1, 0));

//     for (int idx = 0; idx <= n; idx++)
//         dp[0][idx] = idx*price[0];

//     for (int idx = 1; idx < n; idx++) {
//         for (int N = 0; N <= n; N++) {
//             int notTake = dp[idx - 1][N];
//             int take = INT_MIN;

//             int rodlength = idx+1;
//             if (rodlength <= N)
//                 take = price[idx] + dp[idx][N - rodlength];

//             dp[idx][N] = max(take, notTake);
//         }
//     }

//     return dp[n-1][n];
// }

