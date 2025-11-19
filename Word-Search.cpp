class Solution {
    bool helper(int i,int j,vector<vector<char>>&board,string &word,int k)
    {
        int n=board.size();int m=board[0].size();
        if(k==word.length()) return true;

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k]) 
            return false; 
        
        char ch=board[i][j];
        board[i][j]='.';

        bool flag = helper(i+1,j,board,word,k+1) || 
                    helper(i,j+1,board,word,k+1) || 
                    helper(i-1,j,board,word,k+1) || 
                    helper(i,j-1,board,word,k+1);
                
        board[i][j]=ch;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                    if(helper(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};