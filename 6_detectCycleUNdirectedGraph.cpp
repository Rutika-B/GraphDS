https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph7
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int ind,vector<int>adj[],int V,vector<int>&vis)
    {
        
        queue<pair<int,int>>q;
        q.push({ind,-1});
        vis[ind]=1;
        while(!q.empty())
        {
            auto fr=q.front();
int prev=fr.second;
            q.pop();
            for(auto it:adj[fr.first])
            {
                if(it!=prev && vis[it])
                {
                    return 1;
            }
         else if(it!=prev)
            {
                    q.push({it,fr.first});
                  vis[it]=1;
                }
              
          }
        }
        return 0;
    }
    
    // bool dfs(int ind,int prev,vector<int>adj[],int V,vector<int>&vis)
    // {
    //     vis[ind]=1;
    //     for(auto it:adj[ind])
    //     {
    //         if(!vis[it])
    //         {
    //           if(dfs(it,ind,adj,V,vis)==1)
    //           {
    //               return 1;
    //           }
    //         }
    //         else if(it!=prev)
    //         {
    //             return 1;
                
    //         }
            
    //     }
    //     return 0;
    // }
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(bfs(i,adj,V,vis))
                {
                    return 1;
                }
            }
        }
        
        // for(int i=0;i<V;i++)
        // {
        //     if(vis[i]==0)
        //     {
        //         if(dfs(i,-1,adj,V,vis))
        //         {
        //             return 1;
        //         }
        //     }
        // }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends