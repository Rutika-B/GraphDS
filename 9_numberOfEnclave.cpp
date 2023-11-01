https://leetcode.com/problems/number-of-enclaves/description/
class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>grid,vector<vector<int>>&vis,int n,int m)
    {
      queue<pair<int,int>>q;
      int ct=1;
      q.push({i,j});
      cout<<i<<" "<<j<<endl;
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
          cout<<r<<" "<<c<<endl;
          
          if( r>=0 && r<n && c>=0 && c<m)
          {
            if(vis[r][c]==0 && grid[r][c]==1)
            {
                vis[r][c]=1;            
                q.push({r,c});
                cout<<r<<" "<<c<<endl;
                ct++;
                cout<<ct<<endl;
           
            }
          }
        }
      }
      return ct;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0,c=0;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(grid[i][j]==1 )
            {
                c++;
                if((i==0 || i==n-1 || j==0 || j==m-1) && !vis[i][j])
                {
                    count+=bfs(i,j,grid,vis,n,m);
                }
              
              
            }
          }
        }cout<<c<<" "<<count;
        return c-count;
    }
};