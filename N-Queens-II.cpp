class Solution {
    bool canPlace(int x,int y,int n,vector<string>&temp)
    {
        for(int i=0;i<n;i++)
            if(temp[i][y]=='Q') return false;
        
        int j=y;
        for(int i=x;i>=0 && j<n;i--)
            if(temp[i][j++]=='Q') return false;
        

        j=y;
        for(int i=x;i>=0 && j>=0;i--)
            if(temp[i][j--]=='Q') return false;
        
        return true;
    }
    void helper(int i,int n,vector<string>&temp,int &cnt)
    {
        if(i>=n)
        {
            cnt++;return;
        }

        for(int j=0;j<n;j++)
        {
            if(canPlace(i,j,n,temp))
            {
                temp[i][j]='Q';
                helper(i+1,n,temp,cnt);
                temp[i][j]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        if(n==1) return 1;
        int cnt=0;
        vector<string>temp(n,string("."));
        helper(0,n,temp,cnt);
        return cnt;
    }
};