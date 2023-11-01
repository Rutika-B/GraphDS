https://leetcode.com/problems/course-schedule/submissions/1086797624/
class Solution {
public:
    bool dfs(int ind,vector<int>adj[],vector<int>&vis,vector<int>&pathvis)
    {
      vis[ind]=1;
      pathvis[ind]=1;
      for(auto it:adj[ind])
      {
        if(!vis[it])
        {
          if(dfs(it,adj,vis,pathvis))
          {
            return true;
          }
        }
        else if(pathvis[it])
        {
          return true;
        }
      }
      pathvis[ind]=0;
      return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      int n=numCourses;
        vector<int>adj[n];
        for(auto edge: prerequisites){
	        adj[edge[1]].push_back(edge[0]);
	    }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        for(int i=0;i<n;i++)
        {
          if(!vis[i])
          {
            if(dfs(i,adj,vis,pathvis))
            {
              return false;
            }
          }
        }
        return true;
    }
};