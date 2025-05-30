class Solution {
    void helper(int r,int c,vector<vector<int>>&mat,vector<vector<int>>&ans,int n)
    {
        vector<int>temp;
        int i=r,j=c;
        while(i<n && j<mat[0].size())
        {
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
        sort(temp.begin(),temp.end());
        int k=0;i=r,j=c;
        while(i<n && j<mat[0].size())
        {
            ans[i][j]=temp[k++];
            i++;j++;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));

        for(int j=0;j<m;j++)
            helper(0,j,mat,ans,n);

        for(int i=0;i<n;i++)
            helper(i,0,mat,ans,n);

        return ans;   
    }
};