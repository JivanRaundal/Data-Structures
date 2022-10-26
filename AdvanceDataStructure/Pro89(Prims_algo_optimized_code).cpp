// Prims Algorithm (MST) :-
// Time complexity => O((N+E)*log(N)) => O(N*logN) 
// NOTE:- here priority with Min Heap is used
// NOTE:- syntax for priority queue with min heap
// =>   priority_queue<int, vector<int>, greater<int>> pq;		(priority queue with min heap)

#include<bits/stdc++.h>
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
			cout<<"\n--------------------------------------------\n";
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
		
		//Prim's Algorithm
		void Prims()
		{
			//NOTE:- we will require 3 arrays
			int * visited = new int[n];
			int * dist = new int[n];
			int * from = new int[n];
			//initializing this arrays
			for(int i=0; i<n; i++)
			{
				visited[i] = 0;
				dist[i] = INT_MAX;
				from[i] = -1;
			}
			
			//creating priority queue using mean heap
			// NOTE:- we will store pair of distance & source_vertex in queue i.e. pair<distance, vertex>
			priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
			dist[0] = 0;			//0 is considered as source here
			from[0] = -1;
			pq.push({0, 0});
			
			for(int count=0; count<(n-1); count++)
			{
				int v = pq.top().second;
				pq.pop();
				
				//visit vertex with min distance
				visited[v] = 1;
				for(int i=0; i<n; i++)
				{
					if(G[v][i] != 0 && visited[i] == 0)		//find unvisited adjacent vertex
					{
						if(dist[i] > G[v][i])
						{
							dist[i] = G[v][i];
							from[i] = v;
							pq.push({dist[i], i});
						}
					}
				}
			}
			
			cout<<"\nMinimum Spanning Tree Edges\n";
			for(int i=1; i<n; i++)				//note if i is from 0 then (-1 -> 0) is not valid edge
			{
				cout<<"\n"<<from[i]+start<<" -> "<<i+start;
			}
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.Prims();
	
	return 0;
}


