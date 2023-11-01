https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                ans[i][j]=0;
	                vis[i][j]=1;
	                q.push({i,j});
	            }
	            else
	            {
	                ans[i][j]=INT_MAX;
	            }
	        }
	    }
	    int delx[]={-1,+1,0,0};
	    int dely[]={0,0,-1,+1};
	    while(!q.empty())
	    {
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++)
	        {
	            int r=x+delx[i];
	            int c=y+dely[i];
	            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]!=1 && !vis[r][c])
	            {
	                ans[r][c]=min(ans[x][y]+1,ans[r][c]);
	                q.push({r,c});
	                vis[r][c]=1;
	            }
	        }
	        
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends