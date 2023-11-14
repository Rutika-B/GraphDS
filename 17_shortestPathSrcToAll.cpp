https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void f(int src,vector<int>&dist,vector<int>adj[])
    {
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                if(dist[it]>dist[node]+1)
                {
                    q.push(it);
                    dist[it]=dist[node]+1;
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        int l=edges.size();
        vector<int>adj[N];
        for(int i=0;i<l;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>dist(N,1e9);
        
        f(src,dist,adj);
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++)
        {
            if(dist[i]!=1e9)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends