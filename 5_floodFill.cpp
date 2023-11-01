using BFS--https://leetcode.com/problems/flood-fill/
class Solution {
public:
    void bfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>&ans,int color,int delRo[],int delCol[],int iniclr)
    {
      ans[sr][sc]=color;
      queue<pair<int,int>>s;
      s.push({sr,sc});
      int n=image.size();
      int m=image[0].size();
      while(!s.empty())
      {
        int x=s.front().first;
        int y=s.front().second;
        s.pop();
        for(int i=0;i<4;i++)
        {
          int r=x+delRo[i];
          int c=y+delCol[i];
          if(r>=0 && r<n && c>=0 && c<m && image[r][c]==iniclr && ans[r][c]!=color)
            {
                s.push({r,c});
                ans[r][c]=color;
            }
        }
      }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int iniclr=image[sr][sc];
        int delRo[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        bfs(sr,sc,image,ans,color,delRo,delCol,iniclr);
        return ans;
    }
};

using DFS--https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>&ans,int newColor,int delRo[],int delCol[],int iniclr)
    {
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++)
        {
            int r=delRo[i]+sr;
            int c=delCol[i]+sc;
            
            if(r>=0 && r<n && c>=0 && c<m && image[r][c]==iniclr && ans[r][c]!=newColor)
            {
                dfs(r,c,image,ans,newColor,delRo,delCol,iniclr);
            }
        }
    }
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        vector<vector<int>>ans=image;
        int iniclr=image[sr][sc];
        int delRo[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        dfs(sr,sc,image,ans,newColor,delRo,delCol,iniclr);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
