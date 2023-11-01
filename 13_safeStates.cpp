https://leetcode.com/problems/find-eventual-safe-states/
class Solution {
public:
    bool dfs(int ind,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&graph,vector<int>&safenode)
    {
      vis[ind]=1;
      pathVis[ind]=1;

      for(auto it:graph[ind])
      {
        if(!vis[it])
        {
          if(dfs(it,vis,pathVis,graph,safenode)==true)
          {
            safenode[ind]=0;
            return true;
          }
        }
        else if(pathVis[it])
        {
          safenode[ind]=0;
          return true;
        }
      }
      
        safenode[ind]=1;
        pathVis[ind]=0;
      
      
      return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>safenode(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
          if(!vis[i])
          {
            dfs(i,vis,pathVis,graph,safenode);
          }
        }
        for(int i=0;i<n;i++)
        {
          if(safenode[i]==1)
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};