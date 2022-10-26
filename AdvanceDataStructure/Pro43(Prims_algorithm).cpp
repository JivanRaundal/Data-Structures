// Prim's Algorithm :- (Minimum Spanning Tree)

#include<iostream>
#include<limits.h>
#include<climits>
using namespace std;

class Graph
{
	private:
		int ** G;
		int n;
		int dir, wt;
		int start;
	public:
		Graph()
		{
			cout<<"\nEnter the number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			G = new int*[n];
			int i,j;
			for(i=0; i<n; i++)
			{
				G[i] = new int[n];
			}
			//initialize graph to 0
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix();
		void showgraph();
		void Prims();
};

void Graph::readgraph_matrix()
{
	cout<<"\n\nEnter "<<n<<"*"<<n<<" matrix\n";
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cin>>G[i][j];
		}
	}
} 

void Graph::showgraph()
{
	cout<<"\n\nPrinting Graph Matrix\n";
	int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout<<"   "<<G[i][j];
		}
		cout<<"\n";
	}
}

void Graph::Prims()
{
	//create cost matrix & spanning matrix
	int ** cost = new int*[n];
	int ** spanning = new int*[n];
	//initializing spanning matrix to 0 & in cost matrix 0 values in G matrix is replaced by infinity (INT_MAX)
	int i,j;
	for(i=0; i<n; i++)
	{
		cost[i] = new int[n];
		spanning[i] = new int[n];
		for(j=0; j<n; j++)
		{
			spanning[i][j] = 0;
			if(G[i][j] == 0)
			{
				cost[i][j] = INT_MAX;
			}
			else if(G[i][j] != 0)
			{
				cost[i][j] = G[i][j];
			}
		}
	}
	//creating visited, distance & from array
	int * visited = new int[n];
	int * distance = new int[n];
	int * from = new int[n];
	//initializing visited, distance & from array
	//NOTE:- here we are considering 0 as source vertex
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
		distance[i] = cost[0][i];
		from[i] = 0;
	}
	visited[0] = 1;			//mark source vertex i.e. 0 as visited
	
	int ne = n-1;			//ne = no of edges in MST (that much iterations we have to perform)
	int mincost = 0;		//mincost = cost of minimum spanning tree
	int u, v;
	while(ne > 0)
	{
		//find the unvisited vertex with minimum distance
		int min = INT_MAX;
		for(i=0; i<n; i++)
		{
			if(visited[i] == 0 && min > distance[i])
			{
				min = distance[i];
				v = i;				
			}
		}
		//we get the unvisited vertex with min distance, let v be that vertex
		//visit that vertex
		visited[v] = 1;
		//now find vertex u from which vertex v is to be visited
		u = from[v];
		//now, add an edge (u,v) in spanning matrix
		spanning[u][v] = cost[u][v];		// distance[v] 
		spanning[v][u] = cost[u][v];		// distance[v]
		//calculating minimum cost for each edge   added in MST
		mincost = mincost + cost[u][v];		// distance[v] 
		//now, update the distance of unvisited vertices from latest visited vertex v
		for(i=0; i<n; i++)
		{
			if(visited[i] == 0 && distance[i] > cost[v][i])
			{
				distance[i] = cost[v][i];		//update the latest min distance
				from[i] = v;					//from latest visited vertex v
			}
		}
		ne--;
	}
	cout<<"\n\nCost of Minimum Spannig Tree = "<<mincost;
	cout<<"\n\nPrinting Minimum Spanning Tree graph matrix\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			cout<<"    "<<spanning[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	Graph G;
	G.readgraph_matrix();
	G.showgraph();
	G.Prims();
	
	return 0;
}






