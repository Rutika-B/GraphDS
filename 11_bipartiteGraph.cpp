https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool dfs(int ind,int clr,vector<vector<int>>& graph,vector<int>&mat)
    {
      mat[ind]=clr;

      for(auto it:graph[ind])
      {
        if(mat[it]!=-1)
        {
          if(mat[it]==clr)
          {
            return false;
          }
        }
        else
        {          
          if(dfs(it,1-clr,graph,mat)==false)
          {
            return false;
          }
        }
      }
      return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>mat(n,-1);
        for(int i=0;i<n;i++)
        {
          if(mat[i]==-1)
          {
            if(dfs(i,0,graph,mat)==false)
            {
              return false;
            }
          }
        }
      return true;
    }
};