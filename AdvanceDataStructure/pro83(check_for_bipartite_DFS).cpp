// Check if graph is bipartite or not :- (DFS Logic)
// - A graph that can be colored using exactly 2 colors, such that no two adjacent nodes have the same color, is called bipartite 
// graph.
// NOTE:- 2 colors are 0 & 1

#include<iostream>
#include<vector>
#include "Queue.h"
using namespace std;

bool bipartiteDFS(int v,vector<int> adj[],int * color)
{
	if(color[v] == -1)
	{
		color[v] = 0;		//OR 1
	}
	//find adjacent vertices of v
	for(auto it : adj[v])
	{
		if(color[it] == -1)
		{
			color[it] = 1 - color[v];
			if(!bipartiteDFS(it, adj, color))
				return false;
		}
		else if(color[it] == color[v])
		{
			return false;
		}
	}
	return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
	int * color = new int[n];
	for(int i=0; i<n; i++)
	{
		color[i] = -1;
	}
	
	for(int i=0; i<n; i++)
	{
		if(color[i] == -1)
		{
			if(!bipartiteDFS(i, adj, color))
				return false;
		}
	}
	return true;
}

int main()
{
	int n, e, start;
	cout<<"\nEnter number of vertices & edges : ";
	cin>>n>>e;
	cout<<"\nEnter start vertex : ";
	cin>>start;
	
	vector<int> adj[n];			//array of vectors as adjacency list
	
	int u,v;
	cout<<"\nKeep entering egdes in (u,v) format\n";
	for(int i=0; i<e; i++)
	{
		cin>>u>>v;
		adj[u-start].push_back(v-start);
		adj[v-start].push_back(u-start); 
	}
	
	cout<<"\n\nPrinting Adjacency List\n";
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<i+start<<" -> ";
		for(int j=0; j<adj[i].size(); j++)
		{
			cout<<adj[i][j]+start<<" ";
		}
	}
	
	if(checkBipartite(adj, n))
		cout<<"\n\nGraph is Bipartite";
	else
		cout<<"\n\nGraph is not Bipartite";
	
	return 0;
}

