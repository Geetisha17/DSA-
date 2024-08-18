class Solution {
    int helper(int i,int j,vector<vector<int>>&mat,int k,vector<vector<int>>&dp)
    {
        int n=mat.size();
        int m=mat[0].size();

        if(dp[i][j]!=-1) return dp[i][j];

        int r1 = max(0, i - k);
        int c1 = max(0, j - k);
        int r2 = min(n - 1, i + k);
        int c2 = min(m - 1, j + k);

        int sum = 0;
        for (int x = r1; x <= r2; ++x) {
            for (int y = c1; y <= c2; ++y) {
                sum += mat[x][y];
            }
        }

        return dp[i][j] = sum;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = helper(i, j, mat,k, dp);
            }
        }

        return ans;
    }
};