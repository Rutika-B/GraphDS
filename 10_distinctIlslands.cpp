https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int,int>>&v,int basex,int basey,int n,int m)
    {
        vis[i][j]=1;
        v.push_back({i-basex,j-basey});
        
        int delx[]={-1,0,+1,0};
        int dely[]={0,-1,0,+1};
        
        for(int k=0;k<4;k++)
        {
            int r=delx[k]+i;
            int c=dely[k]+j;
            
            if(r>=0 && r<n && c>=0 && c<m)
            {
                if(!vis[r][c] && grid[r][c]==1)
                {
                    v.push_back({i-basex,j-basey});
                    vis[r][c]=1;
                    dfs(r,c,vis,grid,v,basex,basey,n,m);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>v;
                    
                    dfs(i,j,vis,grid,v,i,j,n,m);
                    s.insert(v);
                }
            }
        }
        int ans=s.size();
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends