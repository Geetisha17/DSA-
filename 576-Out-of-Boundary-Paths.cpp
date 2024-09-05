class Solution {
    int mod = 1e9+7;
    int helper(int i,int j,int moves,int maxi,int n,int m,vector<vector<vector<int>>>&dp)
    {
        if(moves > maxi) return 0;
        if(i>=n || j>=m || i<0 || j<0) return 1;

        if (dp[i][j][moves] != -1) return dp[i][j][moves];

        int up = helper(i - 1, j, moves + 1, maxi, n, m, dp);
        int down = helper(i + 1, j, moves + 1, maxi, n, m, dp);
        int left = helper(i, j - 1, moves + 1, maxi, n, m, dp);
        int right = helper(i, j + 1, moves + 1, maxi, n, m, dp);

        return dp[i][j][moves] = ((up + down) % mod + (left + right) % mod) % mod;
    }
public:
    int findPaths(int m, int n, int maxi, int sr, int sc) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxi+1,-1)));
        return helper(sr,sc,0,maxi,m,n,dp);
    }
};