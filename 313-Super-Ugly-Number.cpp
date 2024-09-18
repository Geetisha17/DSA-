class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pt(primes.size(), 1);
        vector<long> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            long mini = LONG_MAX;

            for (int j = 0; j < primes.size(); j++) {
                mini = min(mini, primes[j] * dp[pt[j]]);
            }

            dp[i] = mini;

            for (int j = 0; j < primes.size(); j++) {
                if (primes[j] * dp[pt[j]] == mini) {
                    pt[j]++;
                }
            }
        }

        return dp[n];
    }
};
