class Solution {
    bool canPlace(int x,int y,vector<string>&temp)
    {
        int n=temp.size();

        for(int i=0;i<n;i++) 
            if(temp[i][y]=='Q') return false;
        
        int j=y;
        for(int i=x;i>=0 && j>=0;i--)
        {
            if(temp[i][j]=='Q') return false;
            j--;
        }
        j=y;
        for(int i=x;i>=0 && j<n;i--)
        {
            if(temp[i][j]=='Q') return false;
            j++;
        }
        return true;

        return true;
    }
    void helper(int i,vector<vector<string>>&ans,vector<string>&temp,int n)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }

        for(int j=0;j<n;j++)
        {
            if(canPlace(i,j,temp))
            {
                temp[i][j]='Q';
                helper(i+1,ans,temp,n);
                temp[i][j]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        
        helper(0,ans,temp,n);
        return ans;
    }
};