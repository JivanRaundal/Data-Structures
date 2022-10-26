// Dijkstra's Algorithm (for finding shortest path between source vertex & destination vertex) :-

#include<iostream>
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
			cout<<"\nEnter total number of vertices : ";
			cin>>n;
			cout<<"\nIs your graph directed? Press 1-YES 0-NO : ";
			cin>>dir;
			cout<<"\nIs your graph weighted? Press 1-YES 0-NO : ";
			cin>>wt;
			cout<<"\nEnter start vertex of graph : ";
			cin>>start;
			
			int i,j;
			G = new int*[n];
			for(i=0; i<n; i++)
			{
				G[i] = new int[i];
				for(j=0; j<n; j++)
				{
					G[i][j] = 0;
				}
			}
		}
		
		void readgraph_matrix()
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
		
		void showgraph()
		{
			cout<<"\n\nPrinting graph matrix\n";
			int i,j;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					cout<<"  "<<G[i][j];
				}
				cout<<"\n";
			}
		}
		
		void Dijkstras();
};

void Graph::Dijkstras()		//dijkstra's algorithm code
{
	//create a cost matrix (replace 0 in G matrix by infinity)	
	int ** cost = new int*[n];
	int i,j;
	for(i=0; i<n; i++)
	{
		cost[i] = new int[n];
		for(j=0; j<n; j++)
		{
			if(G[i][j] == 0)
			{
				cost[i][j] = INT_MAX;		//infinity
			}
			else if(G[i][j] != 0)
			{
				cost[i][j] = G[i][j];
			}
		}
	}
	//create visited, distance & from array
	int * visited = new int[n];
	int * distance = new int[n];
	int * from = new int[n];
	//read source vertex from user
	int source;
	cout<<"\nEnter source vertex : ";
	cin>>source;
	source = source - start;		//if start vertex is other than zero (0)			
	//initialize visited, distance & from array using source vertex
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
		distance[i] = cost[source][i];
		from[i] = source;
	}
	//visit the source vertex
	visited[source] = 1;
	
	//---------basic preparation done-----------
	int ne = n-1;			//ne = number of edges
	int min = INT_MAX;
	int v;
	while(ne > 0)
	{	
		//find unvisited vertex with minimum distance
		min = INT_MAX;
		for(i=0; i<n; i++)
		{
			if(visited[i] == 0 && min > distance[i])
			{
				min = distance[i];
				v = i;		
			}
		}
		//let, v be the unvisited vertex with min distance, now visit vertex v
		visited[v] = 1;
		
		//now, update the distance of remaining unvisited vertices from v
		for(i=0; i<n; i++)
		{
			if(visited[i] == 0)
			{
				//NOTE:- if cost[v][i] is INT_MAX, then due to adding some distance[v] in INT_MAX will give -ve value,
				//        which will result in wrong output, hence we are checking if (cost[v][i] != INT_MAX)
				if(cost[v][i] != INT_MAX && distance[i] > distance[v]+cost[v][i])
				{
	
					distance[i] = distance[v] + cost[v][i];
					from[i] = v;
				}
			}
		}
		ne--;
	}
	
	//printing shortes paths
	cout<<"\n\nPrinting Shortest path from "<<source<<" to all vertices\n\n";
	for(int k=0; k<n; k++)
	{
		i = k;						//bcz, we can't change value of k in loop, hence using i 
		while(i != source)
		{
			cout<<i+start<<" -> ";
			i = from[i];
		}
		cout<<source+start<<"\n";
	}
}

int main()
{
	Graph G;
	G.readgraph_matrix();
	G.showgraph();
	G.Dijkstras();
	
	return 0;
}
