// Floyd Warshall's All Pair Shortest Path Algorithm -

/*
NOTE:- Floyd Warshall Algorithm is for solving the All Pairs Shortest Path Problem. The problem is to find shortest distances
       between every pair of vertices in a given edge weighted directed graph. 
*/

#include<iostream>
#include<iomanip>
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
		void warshalls_algo();
		
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
			cout<<" "<<G[i][j];
		}
		cout<<"\n";
	}
}

void Graph::warshalls_algo()
{
	//creating a distance matrix
	int ** dist = new int*[n];
	//copying Graph matrix in dist matrix & 0 in graph matrix are replaced by INF 
	int INF = 214748367;
	for(int i=0; i<n; i++)
	{
		dist[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			if(G[i][j] == 0)
			{
				if(i == j)					//if i == j, then distance will be 0
					dist[i][j] = 0;
				else
					dist[i][j] = INF;
			}
			else 
			{
				dist[i][j] = G[i][j];
			}
		}
	}
	
	//Floyd warshall algorith
	int i,j,k;
	//pick all vertices as a intermediate vertex one by one
	for(k=0; k<n; k++)
	{
		//pick all the vertices as source one by one
		for(i=0; i<n; i++)
		{
			//pick all the vertices as destination for the above picked source
			for(j=0; j<n; j++)
			{
				//if vertex k is on shortest path from i to j, then update the value of dist[i][j]
				if(dist[i][j] > (dist[i][k]+dist[k][j]) && (dist[i][k]!=INF && dist[k][j]!=INF))
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	//printing distance matrix
	cout<<"\n\nPrinting Distance Matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(dist[i][j] == INF)
				cout<<setw(5)<<"INF";
			else
				cout<<setw(5)<<dist[i][j];
		}
		cout<<"\n";
	}
}

int main()
{
	Graph G;
	G.readgraph_matrix();
	G.showgraph();
	G.warshalls_algo();
	
	return 0;
}






