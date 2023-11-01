https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void traverse(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis,int n,int m)
    {
      queue<pair<int,int>>q;
      q.push({i,j});
      while(!q.empty())
      {
        auto fr=q.front();
        q.pop();
        int x=fr.first;
        int y=fr.second;
        
        for(int delrow=-1;delrow<2;delrow++)
        {
          for(int delcol=-1;delcol<2;delcol++)
          {
            int r=delrow+x;
            int c=delcol+y;
            if((r>=0 && r<n) && (c>=0&&c<m) && grid[r][c]=='1' && !vis[r][c])
            {
              vis[r][c]=1;
              q.push({r,c});
            }
          }
        }
          
        

      }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(grid[i][j]=='1' && !vis[i][j])
            {
              c++;
              vis[i][j]=1;
              traverse(i,j,grid,vis,n,m);
            }
            
          }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends





For 4 neighbours --https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void traverse(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&vis,int n,int m)
    {
      queue<pair<int,int>>q;
      q.push({i,j});
      while(!q.empty())
      {
        auto fr=q.front();
        q.pop();
        int x=fr.first;
        int y=fr.second;
        
        
        
          for(int delcol=-1;delcol<2;delcol++)
          {
            int r=x;
            int c=delcol+y;
            if((r>=0 && r<n) && (c>=0&&c<m) && grid[r][c]=='1' && !vis[r][c])
            {
              vis[r][c]=1;
              q.push({r,c});
            }
          }
          if(x!=0 && grid[x-1][y]=='1' && !vis[x-1][y])
          {
            vis[x-1][y]=1;
            q.push({x-1,y});
          }
          if(x!=n-1 && grid[x+1][y]=='1' && !vis[x+1][y])
          {
            vis[x+1][y]=1;
            q.push({x+1,y});
          }
        
      }
    }
    int numIslands(vector<vector<char>>& grid) {
      
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
            if(grid[i][j]=='1' && !vis[i][j])
            {
              c++;
              vis[i][j]=1;
              traverse(i,j,grid,vis,n,m);
            }
            
          }
        }
        return c;
    }
};