class Solution {
    long long binCoeff(int n,int k)
    {
        if(n-k>k)
        k=n-k;

        long long res = 1;
        
        for(int i=0;i<k;i++)
        {
            res *= (n-i);
            res /= (i+1); 
        }
        return res;
    }
public:
    int numTrees(int n) {
        long long ans = binCoeff(2*n,n);
        return ans/(n+1);
    }
};