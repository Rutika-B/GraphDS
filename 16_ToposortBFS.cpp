https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegre[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegre[it]++;
	        }
	    }
	    vector<int>vis(V,0);
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegre[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int>v;
	    while(!q.empty())
	    {
	        v.push_back(q.front());
	        int num=q.front();
	        q.pop();
	        for(auto it:adj[num])
	        {
	            indegre[it]--;
	            if(indegre[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    
	    return v;
	}