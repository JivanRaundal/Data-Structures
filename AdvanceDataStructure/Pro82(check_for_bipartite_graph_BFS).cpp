// Check if graph is bipartite or not :- (BFS Logic)
// - A graph that can be colored using exactly 2 colors, such that no two adjacent nodes have the same color, is called bipartite 
// graph.
// NOTE:- 2 colors are 0 & 1

#include<iostream>
#include<vector>
#include "Queue.h"
using namespace std;

bool bipartiteBFS(int src,vector<int> adj[],int * color)
{
	Queue<int> Q;
	color[src] = 0;		//OR 1
	Q.enqueue(src);
	while(!Q.empty())
	{
		int v = Q.dequeue();
		for(vector<int>::iterator itr = adj[v].begin(); itr < adj[v].end(); itr++)		//for(auto it : adj[i])
		{
			if(color[*itr] == -1)														//if(color[it] == -1)
			{
				color[*itr] = 1 - color[v];												//color[it] = 1 - color[v];	
				Q.enqueue(*itr);														//Q.enqueue(it);
			}
			else if(color[*itr] == color[v])											//else if(color[it]==color[v])
			{
				return false;															//return false
			}
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
			if(!bipartiteBFS(i, adj, color))
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

