https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

void dfs(int ind,vector<int>adj[],vector<int>&vis,stack<int>&s)
	{
	    vis[ind]=1;
	    for(auto it:adj[ind])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,s);
	        }
	    }
	    s.push(ind);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    stack<int>s;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int>v;
	    while(!s.empty())
	    {
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	}