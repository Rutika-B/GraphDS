https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int wt=edges[i][2];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int nodeWt=it.first;
            for(auto jt:adj[node])
            {
                int adjNode=jt.first;
                int adjWt=jt.second;
                if(dist[adjNode]>adjWt+nodeWt)
                {
                    dist[adjNode]=adjWt+nodeWt;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int>path;
        int i=n;
        while(parent[i]!=i)
        {
            path.push_back(i);
            i=parent[i];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends