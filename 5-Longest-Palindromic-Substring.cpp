class Solution {
    bool isPalin(const string &s, int st, int e, vector<vector<int>> &dp) {
        if (st >= e) return 1;
        if (dp[st][e] != -1) return dp[st][e];

        if (s[st] == s[e]) {
            return dp[st][e] = isPalin(s, st + 1, e - 1, dp);
        } 

        return dp[st][e] = 0;
    }

public:
    string longestPalindrome(const string &s) {
        int n = s.length();
        if (n == 0) return \\;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxi = 0;
        int st = 0;

        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                if (isPalin(s,i,j,dp)) {
                    if (j-i+1 > maxi) {
                        maxi = j - i + 1;
                        st = i;
                    }
                }
            }
        }

        return s.substr(st, maxi);
    }
};
