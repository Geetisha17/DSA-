class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1,-1);
        int i1=2,i2=3,i3=5;

        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i] = 2*i2;
            dp[]
        }
    }
};