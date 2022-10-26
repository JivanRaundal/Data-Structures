// Dijkstra's Algorithm (optimized) :-
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
		
		//Dijkstra's Algorithm
		void Dijkstra()
		{
			int src;
			cout<<"\nEnter source vertex : ";
			cin>>src;
			src = src - start;		//if start vertex is other than zero
			
			//creating & initializing distance array
			int * dist = new int[n];
			for(int i=0; i<n; i++)
				dist[i] = INT_MAX;
				
			//crating priority queue using min heap
			// NOTE:- we will store pair of distance & source_vertex in queue i.e. pair<distance, vertex>
			priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
			
			dist[src] = 0;
			pq.push({0, src});		//pq.push({distance, vertex});
			while(!pq.empty())
			{
				int w = pq.top().first;
				int v = pq.top().second;		//this is vertex with minimum distance
				pq.pop();
				
				for(int i=0; i<n; i++)
				{
					if(G[v][i] != 0)
					{
						if(dist[i] > dist[v] + G[v][i])			
						{
							dist[i] = dist[v] + G[v][i];
							pq.push({dist[i], i});
						}
					}
				}
			}
			
			cout<<"\nShortest Distance of every vertex from source vertex is\n";
			for(int i=0; i<n; i++)
			{
				cout<<"\n"<<src+start<<" -> "<<i+start<<" = "<<dist[i];
			}
		}
};

int main()
{
	Graph G;
	G.readgraph();
	G.showgraph();
	G.Dijkstra();
	
	return 0;
}


