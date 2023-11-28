https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            auto fr=pq.top();
            pq.pop();
            int efforts=fr.first;
            int i=fr.second.first;
            int j=fr.second.second;
            if(i==n-1 && j==m-1)
            {
                return dist[i][j];
            }
            int row[]={0,0,-1,+1};
            int col[]={+1,-1,0,0};
            
            for(int k=0;k<4;k++)
            {
                int newRo=row[k]+i;
                int newCol=col[k]+j;
                if(newRo>=0 && newRo<n && newCol>=0 && newCol<m)
                {
                    int diff=abs(heights[i][j]-heights[newRo][newCol]);
                    int newEffort=max(efforts,diff);
                    if(dist[newRo][newCol]>newEffort)
                    {
                        dist[newRo][newCol]=newEffort;
                        pq.push({newEffort,{newRo,newCol}});
                    }
                }
                
            }
            
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends