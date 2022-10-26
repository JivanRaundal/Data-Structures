// Shortest path in Weighted Directed Acyclic Graph (DAG) :- (Topological Sort Logic)

#include<iostream>
#include<iomanip>
#include<climits>
#include "Stack.h"
using namespace std;

class Graph
{
	private:
		int ** G;
		int n;
		int dir, wt, start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs yout graph directed ? 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted ? 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			G = new int*[n];
			for(int i=0; i<n; i++)
			{
				G[i] = new int[n];
				for(int j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph()
		{
			int u,v,w=1;
			if(wt == 0)
			{
				cout<<"\nKeep entering edges in the form (u,v) & enter -1 to stop\n";
				while(1)
				{
					cin>>u>>v;
					if(u==-1 || v==-1)
					{
						break;
					}
					insert(u-start, v-start, w);		//here w = 1
				}
			}
			else if(wt == 1)
			{
				cout<<"\nKeep entering edges in the form (u,v,w) & enter -1 to stop\n";
				while(1)
				{
					cin>>u>>v>>w;
					if(u==-1 || v==-1 || w==-1)
					{
						break;
					}
					insert(u-start, v-start, w);
				}
			}
		}
		
		void insert(int u,int v,int w)
		{
			G[u][v] = w;
			if(dir == 0)
			{
				G[v][u] = w;
			}
		}
		
		void showgraph()
		{
			cout<<"\n\nPrinting Graph Matrix\n";
			cout<<"    ";
			for(int i=0; i<n; i++)
			{
				cout<<setw(5)<<i+start;
			}
			cout<<"\n----------------------------------------\n";
			for(int i=0; i<n; i++)
			{
				cout<<i+start<<" | ";
				for(int j=0; j<n; j++)
				{
					cout<<setw(5)<<G[i][j];
				}
				cout<<"\n";
			}
		}
		
		void topoSort(int v,int * visited, Stack<int>& st)
		{
			visited[v] = 1;
			for(int i=0; i<n; i++)
			{
				if(G[v][i] != 0 && visited[i] == 0)
				{
					topoSort(i, visited, st);
				}
			}
			st.push(v);
		}
		
		//find shortest path in undirected graph with unit weights
		void shortestPathDAG(int src)
		{
			int * visited = new int[n];
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
			}
			Stack<int> st;
			for(int i=0; i<n; i++)
			{
				if(visited[i] == 0)
					topoSort(i, visited, st);
			}
			
			int * dist = new int[n];
			for(int i=0; i<n; i++)
			{
				dist[i] = INT_MAX;
			}
			dist[src] = 0;
			while(!st.empty())
			{
				int v = st.pop();
				if(dist[v] != INT_MAX)
				{
					for(int i=0; i<n; i++)
					{
						if(G[v][i] != 0)
						{
							if(dist[i] > dist[v] + G[v][i])
							{
								dist[i] = dist[v] + G[v][i];
							}
						}
					}
				}
			}
			
			cout<<"\nShortest Distance of every vertex in DAG from source vertex is\n";
			for(int i=0; i<n; i++)
			{
				cout<<"\n"<<src+start<<" -> "<<i+start<<" = "<<dist[i];
			}
		}
		
		void shortestPath()
		{
			int src;
			cout<<"\nEnter source vertex : ";
			cin>>src;
			src = src - start;
			shortestPathDAG(src);
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.shortestPath();
	
	return 0;
}


