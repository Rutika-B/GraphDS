https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first==destination.first && source.second==destination.second)
        {
            return 0;
        }
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});
        while(!q.empty())
        {
            auto fr=q.front();
            q.pop();
            int wt=fr.first;
            int i=fr.second.first;
            int j=fr.second.second;
            int row[]={0,0,-1,+1};
            int col[]={+1,-1,0,0};
            for(int k=0;k<4;k++)
            {
                int x=row[k]+i;
                int y=col[k]+j;
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && dist[x][y]>dist[i][j]+1)
                {
                    if(x==destination.first && y==destination.second)
                    {
                        return wt+1;
                    }
                    dist[x][y]=wt+1;
                    q.push({wt+1,{x,y}});
                }
            }
        }
        return -1;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends