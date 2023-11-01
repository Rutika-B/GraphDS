https://leetcode.com/problems/surrounded-regions/
class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis,int n,int m)
    {
      queue<pair<int,int>>q;
      q.push({i,j});
      vis[i][j]=1;
      int delx[]={-1,+1,0,0};
      int dely[]={0,0,-1,+1};
      while(!q.empty())
      {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
          int r=delx[i]+x;
          int c=dely[i]+y;
          if(board[r][c]=='O' && r>=0 && r<n && c>=0 && c<m && !vis[r][c])
          {
            
            vis[r][c]=1;
            q.push({r,c});
          }
        }
      }
    }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1))
            {
              bfs(i,j,board,vis,n,m);
              
            }
          }
        }
        
    }
};