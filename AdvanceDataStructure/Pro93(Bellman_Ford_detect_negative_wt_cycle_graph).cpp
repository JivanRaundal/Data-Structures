// Bellman Ford Algorithm (to find shortest path in case of negative weights & to detect negative cycle in graph)
// NOTE:- Dijkstra's algo doesn't work for -ve weights, but Bellman Ford algo works.

#include<bits/stdc++.h>
using namespace std;

class Edge
{
	public:
		int u,v,w;
		Edge()
		{
			u = v = w = 0;
		}
};

int main()
{
	int N, M;
	cout<<"\nEnter total vertices & total number of edges in graph : ";
	cin>>N>>M;
	
	//create array of Edge class objects
	Edge * elist = new Edge[M];
	cout<<"\nEnter edges\n";
	for(int i=0; i<M; i++)
	{
		cin>>elist[i].u>>elist[i].v>>elist[i].w;
	}
	
	//create distance array
	int * dist = new int[N];
	for(int i=0; i<N; i++)
	{
		dist[i] = INT_MAX;
	}
	int src;
	cout<<"\nEnter source vertex : ";
	cin>>src;
	dist[src] = 0;
	
	//perform (N-1) iterations
	for(int i=1; i<=(N-1); i++)
	{
		//traverse through elist array each time & update the dist array
		for(int j=0; j<M; j++)
		{
			if( dist[elist[j].u] != INT_MAX && (dist[elist[j].u] + elist[j].w < dist[elist[j].v]) )
			{
				dist[elist[j].v] = dist[elist[j].u] + elist[j].w;
			}
		}
	}
	
	//NOTE:- to check -ve cycle in graph, do one more iteration & if dist of any node changes, then graph contains -ve cycle
	int flag=0;
	for(int j=0; j<M; j++)
	{
		if(dist[elist[j].u] + elist[j].w < dist[elist[j].v])
		{
			flag=1;
			cout<<"\n\nNegative Cycle Detected";
			break;	
		}
	}
	
	if(flag==0)
	{
		cout<<"\n\nShortest Distance of every vertex from "<<src<<" vertex\n";
		for(int i=0; i<N; i++)
		{
			cout<<src<<" -> "<<i<<" = "<<dist[i]<<endl;
		}
	}
	
	return 0;
}
