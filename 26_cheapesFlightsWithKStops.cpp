https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1103013875/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
          adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
          auto fr=q.front();
          q.pop();
          int stops=fr.first;
          int node=fr.second.first;
          int cost=fr.second.second;
          if(stops>k)continue;
          for(auto it:adj[node])
          {
            int adjNode=it.first;
            int adjCost=it.second;
            if(stops<=k && dist[adjNode]>adjCost+cost)
            {
              dist[adjNode]=adjCost+cost;
              q.push({stops+1,{adjNode,adjCost+cost}});
            }
          }
        }
      if(dist[dst]==1e9)
        return -1;
      return dist[dst];
    }
};