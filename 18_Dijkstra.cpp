https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

https://leetcode.com/problems/path-with-maximum-probability/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            auto tp = pq.top();
            pq.pop();
            int d = tp.first;
            int node = tp.second;
            for (auto it : adj[node])
            {
                int val = it[0];
                int len = it[1];
                if (dist[val] > d + len)
                {
                    dist[val] = d + len;
                    pq.push({d + len, val});
                }
            }
        }
        return dist;
    }
};

//--------------------------------Using Set-----------------------------------------------

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    set<pair<int, int>> s;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    s.insert({0, S});
    while (!s.empty())
    {
        auto it = *(s.begin());
        int node = it.second;
        int nodeWt = it.first;
        s.erase(it);
        for (auto i : adj[node])
        {
            int adjnode = i[0];
            int adjwt = i[1];
            if (dist[adjnode] > adjwt + nodeWt)
            {
                if (dist[adjnode] != 1e9)//set ds used to remove node who gets max cost as compared to another to reach same node
                {
                    s.erase({dist[adjnode], adjnode});
                }
                dist[adjnode] = adjwt + nodeWt;
                s.insert({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends