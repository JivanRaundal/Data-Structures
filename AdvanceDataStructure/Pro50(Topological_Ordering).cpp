// Topological Ordering :- (Topological Sort)
// Note:- Graph should be directed & acyclic for topological sort.

#include<iostream>
using namespace std;

class Graph
{
	public:
		int ** G;
		int n;
		Graph()
		{
			cout<<"\nEnter number of vertices : ";
			cin>>n;
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
			cout<<"\n\nEnter "<<n<<"*"<<n<<" matrix\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cin>>G[i][j];
				}
			}
		}
		void showgraph()
		{
			cout<<"\n\nPrinting Graph\n";
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<"  "<<G[i][j];
				}
				cout<<"\n";
			}
		}
};

void topological_ordering()
{
	Graph graph;
	graph.readgraph();
	graph.showgraph();
	
	//creating & initializing visited array
	int i,j,k;
	int * visited = new int[graph.n];
	for(i=0; i<graph.n; i++)
	{
		visited[i] = 0;
	}
	//creating & initializing indegree array
	int * indegree = new int[graph.n];
	for(i=0; i<graph.n; i++)
	{
		indegree[i] = 0;
		for(int j=0; j<graph.n; j++)
		{
			if(graph.G[j][i] != 0)		//count nonzero entries in column of vertex j
			{
				indegree[i]++;	
			}
		}
	}
	
	//Topological ordering process starts here
	for(i=0; i<graph.n; i++)
	{
		j = 0;
		while(j < graph.n)
		{
			if(visited[j] == 0 && indegree[j] == 0)
			{
				visited[j] = 1;
				cout<<"\nvisited = "<<j;
				for(k=0; k<graph.n; k++)
				{
					//find adjacent vertices of vertex j & decrease it's adjacent vertices indegree by 1
					if(graph.G[j][k] != 0)
					{
						indegree[k]--;	
					}
				}
				break;
			}
			j++;
		}
		if(j == graph.n)
		{
			cout<<"\n\nCyclic Graph";
			break;
		}
	}	
}

int main()
{
	topological_ordering();
		
	return 0;
}
