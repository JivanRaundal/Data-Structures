// Kosaraju's Algorithm (to find Strongly Connected Components in Directed Graph) :-

/* Steps:- 
1. Sort all nodes in order of finishing time (i.e. perform topological sort & store nodes in stack)
2. Transpose the graph
3. perform DFS for nodes according to topological ordering
*/

#include<bits/stdc++.h>
using namespace std;

void topoDFS(int v, vector<int>& vis, stack<int>& st, vector<int> adj[])
{
	vis[v] = 1;
	for(auto it : adj[v])
	{
		if(!vis[it])
		{
			topoDFS(it, vis, st, adj);
		}
	}
	st.push(v);
}

int start;			//global var

void DFS(int v, vector<int> &vis, vector<int> transpose[])
{
	vis[v] = 1;
	cout<<" "<<v+start;
	for(auto it : transpose[v])
	{
		if(!vis[it])
		{
			DFS(it, vis, transpose);
		}
	}
}

int main()
{
	int n;
	//int start;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;
	cout<<"\nEnter start vertex : ";
	cin>>start;
	vector<int> adj[n];				//adjacency matrix
	
	cout<<"\nKeep entering edges or -1 to stop\n";
	int u,v;
	while(1)
	{
		cin>>u>>v;
		if(u==-1 || v==-1)
		{
			break;
		}
		adj[u-start].push_back(v-start);			//only edge(u,v) and not edge(v,u) bcz graph is directed
	}
	
	cout<<"\n\nPrinting Graph\n";
	for(int i=0; i<n; i++)
	{
		cout<<i+start<<" -> ";
		for(auto it : adj[i])
		{
			cout<<it+start<<" ";
		}
		cout<<"\n";
	}
	
	//perform topological sort
	vector<int> vis(n, 0);
	stack<int> st;
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			topoDFS(i, vis, st, adj);
		}
	}
	
	//Transpose the graph
	vector<int> transpose[n+1];		//transpose graph matrix
	for(int i=0; i<n; i++)
	{
		vis[i] = 0;					//for dfs next time
		for(auto it : adj[i])
		{
			transpose[it].push_back(i);
		}
	}
		
	//perform dfs for nodes according to topological order
	while(!st.empty())
	{
		int v = st.top();
		st.pop();
		if(!vis[v])
		{
			cout<<"\nSCC : ";
			DFS(v, vis, transpose);
		}
	}
	
	return 0;
}
