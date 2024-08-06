class Solution {
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[nr][nc]=1;

        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr = r+delRow[i];
            int nc = c+delCol[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==\O\)
            {
                dfs(nr,nc,grid,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]=='O')
            {
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O')
            {
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]=='O')
            {
                dfs(0,j,grid,vis);
            }
            if(!vis[n-1][i] && grid[n-1][i]=='O')
            {
                dfs(n-1,i,grid,vis);
            }
        }
    }
};